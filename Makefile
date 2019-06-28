BUILD_ID?=$(BUILD_ID)
CC=gcc
EXE_BUILD_DIR=out
OBJ_BUILD_DIR=out/object

TEST_BUILT_NAME=chaerengine_test
STABLE_BUILT_NAME=chaerengine_stable

DEFAULT_BUILD_MODE=test

all: $(DEFAULT_BUILD_MODE) clean

chaerengine.o:
	$(CC) -c chaerengine.c -o $(OBJ_BUILD_DIR)/chaerengine.o

statemanager.o: src/statemanager.h
	$(CC) -c src/statemanager.c -o $(OBJ_BUILD_DIR)/statemanager.o

test: chaerengine.o statemanager.o
	$(CC) $(OBJ_BUILD_DIR)/*.o -o $(EXE_BUILD_DIR)/$(TEST_BUILT_NAME)_$(BUILD_ID)

stable: chaerengine.o statemanager.o
	$(CC) $(OBJ_BUILD_DIR)/*.o -o $(EXE_BUILD_DIR)/$(STABLE_BUILT_NAME)_$(BUILD_ID)

clean:
	rm $(OBJ_BUILD_DIR)/*.o