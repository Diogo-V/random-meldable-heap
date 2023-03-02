compiler = gcc
flags = -Wall -Wpedantic -Wextra -Werror=format-security -g -lm -O3

source_code = ./src/*.c

# Compiles everything
c: src/main.c
	@$(compiler) $(flags) -o ./bin/main $(source_code)

# Checks code complexity with lizard
l: src/main.c
	@lizard -T parameter_count=9 -T token_count=500 -T length=150 -T cyclomatic_complexity=15 $(source_code)

# Runs main program
r:
	@./bin/main	

# Runs main against test 1
t1:
	@./bin/main < ./tests/T01/input.txt > ./tests/T01/my_result.txt
	@diff ./tests/T01/output.txt ./tests/T01/my_result.txt

# Runs main against test 2
t2:
	@./bin/main < ./tests/T02/input.txt > ./tests/T02/my_result.txt
	@diff ./tests/T02/output.txt ./tests/T02/my_result.txt

# Runs main against test 3
t3:
	@./bin/main < ./tests/T03/input.txt > ./tests/T03/my_result.txt
	@diff ./tests/T03/output.txt ./tests/T03/my_result.txt

# Runs main against test 4
t4:
	@./bin/main < ./tests/T04/input.txt > ./tests/T04/my_result.txt
	@diff ./tests/T04/output.txt ./tests/T04/my_result.txt

# Cleans binaries
clean:
	rm -f ./bin/*