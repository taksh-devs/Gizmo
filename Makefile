# Compiler and flags
CC = g++
CFLAGS = -I -L lib/glad/include -L lib/glfw/include -L lib/osdialog/src -L lib/spdlog/include

# Linker and flags
LD = gcc
LDFLAGS = -L lib/glad/src -L lib/glfw/src -L lib/osdialog/src -L lib/spdlog/src

# List of object files needed for the final executable
OBJ = main.o glad.o glfw.o osdialog.o spdlog.o

# Name of the final executable
EXECUTABLE = gizmo

# Target to build the executable
$(EXECUTABLE): $(OBJ)
    $(LD) $(LDFLAGS) $(OBJ) -l glad -l glfw -l osdialog -l spdlog -o $(EXECUTABLE)

# Rules to build object files from source files
main.o: main.cpp
    $(CC) $(CFLAGS) -c main.c -o main.o


glad.o: glad.c
    $(CC) $(CFLAGS) -c glad.c -o glad.o

osdialog.o: glfw.c
    $(CC) $(CFLAGS) -c glfw.c -o glfw.o

osdialog.o: osdialog.c
    $(CC) $(CFLAGS) -c osdialog.c -o osdialog.o

spdlog.o: spdlog.c
    $(CC) $(CFLAGS) -c spdlog.c -o spdlog.o

# Clean rule to remove generated files
clean:
    rm -f $(EXECUTABLE) $(OBJ)
