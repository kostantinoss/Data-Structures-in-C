SRC_DIR := ./src
BUILD_DIR := build

BIN_DIR := ./bin
TARGET := hash_table

CC := gcc
CFLAGS := -g $(INCLUDE)

SRC_FILES := $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRC_FILES))


build: $(BUILD_DIR)/main.o $(BUILD_DIR)/hash_table.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/hash_table.o -o $(BIN_DIR)/$(TARGET)


$(BUILD_DIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(BUILD_DIR)/main.o 


$(BUILD_DIR)/hash_table.o: $(SRC_DIR)/hash_table.c
	$(CC) $(CFLAGS) -c $(SRC_DIR)/hash_table.c -o $(BUILD_DIR)/hash_table.o

clean:
	rm -rf $(BIN_DIR)/$(TARGET) $(BUILD_DIR)/*.o