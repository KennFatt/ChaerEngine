BUILD_ID?=$(BUILD_ID)
DEFAULT_BUILD_MODE?=$(DEFAULT_BUILD_MODE)
LIB_FLAGS=-lSDL2
CC=gcc
EXE_BUILD_DIR=out/$(DEFAULT_BUILD_MODE)
OBJ_BUILD_DIR=out/$(DEFAULT_BUILD_MODE)/object

TEST_BUILT_NAME=chaerengine_test
STABLE_BUILT_NAME=chaerengine_stable

all: $(DEFAULT_BUILD_MODE) clean

chaerengine.o:
	$(CC) -c chaerengine.c -o $(OBJ_BUILD_DIR)/chaerengine.o

unittest.o: unittest.h
	$(CC) -c unittest.c -o $(OBJ_BUILD_DIR)/unittest.o

statemanager.o: src/statemanager.h
	$(CC) -c src/statemanager.c -o $(OBJ_BUILD_DIR)/statemanager.o

graphics.o: src/graphics.h
	$(CC) -c src/graphics.c -o $(OBJ_BUILD_DIR)/graphics.o

test: chaerengine.o statemanager.o graphics.o unittest.o
	$(CC) $(OBJ_BUILD_DIR)/*.o -o $(EXE_BUILD_DIR)/$(TEST_BUILT_NAME)_$(BUILD_ID) $(LIB_FLAGS)

stable: chaerengine.o statemanager.o graphics.o unittest.o
	$(CC) $(OBJ_BUILD_DIR)/*.o -o $(EXE_BUILD_DIR)/$(BUILD_ID)/$(STABLE_BUILT_NAME)_$(BUILD_ID) $(LIB_FLAGS)

clean:
	rm $(OBJ_BUILD_DIR)/*.o