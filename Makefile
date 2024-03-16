# VARIABLES
## Directories
SRC_DIR=src
BUILD_DIR=build
TEST_DIR=test
INC_DIR=include

## Compilation flags
CFLAGS= -std=c99 -pedantic -Wall -Wextra -I./$(INC_DIR)/ -DUSE_ASSERT
LDFLAGS= -lm -lpthread -O3 -ffast-math

## Sources
OBJFILES = $(BUILD_DIR)/base.o
OBJFILES += $(BUILD_DIR)/arena_alloc.o
OBJFILES += $(BUILD_DIR)/str.o

# PATTERN RULES
## Build object files
$(OBJFILES): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -c $< $(CFLAGS) -o $@

# FILE RULES
## Build library
$(BUILD_DIR)/libelm.a: $(OBJFILES)
	$(AR) -rcs $@ $(BUILD_DIR)/*.o

## Build test binary
$(BUILD_DIR)/test: $(TEST_DIR)/main.c $(BUILD_DIR)/libelm.a
	$(CC) $(TEST_DIR)/*.c $(BUILD_DIR)/libelm.a $(CFLAGS) $(LDFLAGS) -o $@

## Build test_gdb binary
$(BUILD_DIR)/test_gdb : $(TEST_DIR)/main.c $(BUILD_DIR)/libelm.a
	$(CC) -ggdb $(TEST_DIR)/*.c $(BUILD_DIR)/libelm.a $(CFLAGS) $(LDFLAGS) -o $@

# PHONY RULES
## Define phony rules
.PHONY: clean build test gdb

## Clean: clears build directory
clean:
	rm -rf $(BUILD_DIR)/*

## Build: builds libelm.a
build: $(BUILD_DIR)/libelm.a

## Test: builds and runs test binary
test: $(BUILD_DIR)/test
	$(BUILD_DIR)/test

## GDB: builds the test binary with debug symbols and starts gdb
gdb: $(BUILD_DIR)/test_gdb
	gdb $(BUILD_DIR)/test_gdb
