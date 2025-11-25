CC = gcc
FLAGS = -Wall -Wextra
SRC_DIRECTORY = src
BUILD_DIR = build

.PHONY: all clean

all: $(BUILD_DIR)/ArrayList.o

$(BUILD_DIR)/%.o: $(SRC_DIRECTORY)/%.c | $(BUILD_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
