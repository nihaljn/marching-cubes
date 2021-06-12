CC = g++
CFLAGS = -Wall -O2 -g -I include

march_objects = build/marching_cubes.o build/generator.o build/utilities.o build/main_march.o

main_march: $(march_objects)
	$(CC) $(CFLAGS) $(march_objects) -o main_march

build/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@


build/utilities.o: include/utilities.hpp

build/main_march.o:
build/marching_cubes.o: include/marching_cubes.hpp include/types.hpp
build/generator.o: include/types.hpp