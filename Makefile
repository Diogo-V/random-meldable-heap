compiler = gcc
flags = -Wall -Wpedantic -Wextra -Werror=format-security -g -lm -O2

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

# Cleans binaries
clean:
	rm -f ./bin/*