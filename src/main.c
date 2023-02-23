#include "stdlib.h"
#include "stdio.h"
#include "string.h"

#define _NULL 0


/* ################################ Globals ################################ */


/**
 * @brief heap node definition.
 * 
 * @param value the value to store
 * @param left left child
 * @param right right child
 * @param hook pointer to field in the father node
 */
typedef struct node {
  int value;                    
  struct node* left;   
  struct node* right;  
  struct node** hook;
} *Node;

/**
 * @brief number of nodes present in the array of nodes.
 */
int number_of_nodes = -1;

/**
 * @brief nodes pointer array that has 'number_of_nodes' size.
 */
Node nodes;


/* ################################# Nodes ################################# */


/**
 * @brief Gets index of node in nodes array.
 * 
 * @param node node to fetch the index from
 * 
 * @return int node index in nodes array
 */
int ptr_to_loc(Node node) {
  int r;
  r = -1;
  if(_NULL != node) r = ((size_t) node - (size_t) nodes) / sizeof(struct node);
  return (int) r;
}

/**
 * @brief Shows input node information.
 * 
 * @param node node to print the information from
 */
void show_node(Node node) {
  int f;
  if(_NULL == node)
    printf("NULL\n");
  else {
    printf("node: %d ", ptr_to_loc(node));
    printf("v: %d ", node->value);
    printf("leftChild: %d ", ptr_to_loc(node->left)); 
    printf("rightChild: %d ", ptr_to_loc(node->right));
    f = ptr_to_loc((Node) node->hook);
    printf("father: %c %d", &(nodes[f].left) == node->hook ? 'l' : 'r', f);
    printf("\n");
  }
}


/* ################################# Funcs ################################# */


/**
 * @brief Randomly generates 0 or 1 to decide if we are going to meld the heaps
 * in the left (0) or the right (1) child.
 * 
 * @return int 0 or 1
 */
static int random_bit(void) {

  static unsigned int M = 0; 
  static unsigned int P; 
  int r;

  if(0 == M){
    M = ~0;
    P = random();
  }

  r = P & 1;
  M = M>>1;
  P = P>>1;

  printf("Flipped a %d\n", r);
  return r; 
}

/**
 * @brief Before executing the function, we print the final configuration of the heap.
 */
void finish_execution() {
  printf("Final configuration:\n");
  for (int i = 0; i < number_of_nodes; i++) {
    show_node(&nodes[i]);
  }
}

/**
 * @brief Decides which function to execute based on the input from the stdin.
 * 
 * @param input input from stdin that corresponds to a valid command
 */
void control_command(char* input) {
  int command = input[0];

  switch (command) {
    case 'S':  // Shows node information
      int node = 0;
      sscanf(input, "%s %d", command, &node);
      printf("node: %d\n", node);
      break;

    case 'P':  // Displays whole heap recursively
      break; 

    case 'V':  // Displays whole heap recursively
      break; 

    case 'U':  // Displays whole heap recursively
      break; 
    
    case 'R':  // Displays whole heap recursively
      break; 
    
    case 'M':  // Displays whole heap recursively
      break; 

    case 'A':  // Displays whole heap recursively
      break;

    case 'E':  // Displays whole heap recursively
      break; 
    
    case 'D':  // Displays whole heap recursively
      break; 

    case 'X':  // Stop invocation
      break;

    default:
      printf("Command not supported!\n");
      break;
  }
}

/**
 * @brief Main driver code.
 * 
 * @return int 0 for success or 1 for error
 */
int main() {

  /* Used as parameters in getline to store input and size of input */ 
  size_t len = 0;
  char* input = _NULL;

  /* Reads number of nodes in the array and allocates memory for it */
  getline(&input, &len, stdin);
  number_of_nodes = input[0];
  nodes = (Node) calloc(number_of_nodes, sizeof(struct node));

  do {
    memset(input, 0, len);
    getline(&input, &len, stdin);
    control_command(input);
  } while (input[0] != 'X');

  // finish_execution();
  free(input);
  free(nodes);
  exit(0);
}
