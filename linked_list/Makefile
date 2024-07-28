SRC_DIR := ./src
BUILD_DIR := build

BIN_DIR := ./bin
TARGET := linked_list

CC := gcc
CFLAGS := -g $(INCLUDE)

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))


build: $(BUILD_DIR)/main.o $(BUILD_DIR)/linked_list.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/linked_list.o -o $(BIN_DIR)/$(TARGET)


$(BUILD_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(BUILD_DIR)/main.o 


$(BUILD_DIR)/linked_list.o: $(SRC_DIR)/linked_list.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/linked_list.c -o $(BUILD_DIR)/linked_list.o

clean:
	rm -rf $(BIN_DIR)/$(TARGET) $(BUILD_DIR)/*.o