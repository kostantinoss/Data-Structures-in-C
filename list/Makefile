SRC_DIR := ./src
BUILD_DIR := build

BIN_DIR := ./bin
TARGET := list

CC := gcc
CFLAGS := -g

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))


build: $(BUILD_DIR)/main.o $(BUILD_DIR)/list.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/list.o -o $(BIN_DIR)/$(TARGET)


$(BUILD_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(BUILD_DIR)/main.o 

# Build src files.
$(BUILD_DIR)/list.o: $(SRC_DIR)/list.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/list.c -o $(BUILD_DIR)/list.o

clean:
	rm -rf $(BUILD_DIR)/*.o