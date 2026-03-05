# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -Wall -Wextra -O2

# Executable name
TARGET = game

# Source files
SRC = my_game.c

# Build rule
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove the executable
clean:
	rm -f $(TARGET)
