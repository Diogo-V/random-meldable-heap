CC = gcc
debug_flags = -Wall -std=c++14 -g -lm
compile_flags = -Wall -std=c++14 -g -lm

source_code = ./src/*.c ./src/*.h

# Compiles everything
c: src/main.cpp
	$(CC) $(compile_flags) -o ./bin/main $(source_code)

# Runs main algorithm
r: c
	./bin/main	

# Cleans binaries
clean:
	rm -f ./bin/*