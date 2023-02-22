compiler = gcc
flags = -Wall -Wpedantic -Wextra -Werror=format-security -g -lm -O2

source_code = ./src/*.c

# Compiles everything
c: src/main.c
	@$(compiler) $(flags) -o ./bin/main $(source_code)

# Runs main algorithm
r: c
	@./bin/main	

# Cleans binaries
clean:
	rm -f ./bin/*