CC = gcc
CFLAGS = -Wall -Wextra -g
SRC_DIR = ../../src
INC_DIR = ../../inc
BUILD_DIR = bin
TARGET = test

SOURCES = $(SRC_DIR)/json.c test.c
OBJECTS = $(BUILD_DIR)/json.o $(BUILD_DIR)/test.o

all: $(TARGET)

$(TARGET): $(BUILD_DIR)/json.o $(BUILD_DIR)/test.o
	$(CC) $(CFLAGS) -o $@ $^ -I$(INC_DIR)

$(BUILD_DIR)/json.o: $(SRC_DIR)/json.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

$(BUILD_DIR)/test.o: test.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean