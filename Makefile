# Compiler
CXX ?= g++
CXXFLAGS ?= -Wall -Wextra -pedantic -std=c++20 -Wno-comment

# Directories
SRC_DIR ?= src
INC_DIR ?= src
BUILD_DIR ?= build
OBJ_DIR ?= $(BUILD_DIR)/obj
BIN_DIR ?= $(BUILD_DIR)/bin

# Source files
SRCS ?= $(wildcard $(SRC_DIR)/*.cpp)
OBJS ?= $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

# Build mode
BUILD_MODE ?= RELEASE

ifeq ($(BUILD_MODE),DEBUG)
    CXXFLAGS += -g
endif
ifeq ($(BUILD_MODE),RELEASE)
    CXXFLAGS += -O3 -s
endif

# Targets
.PHONY: all clean

all: $(BIN_DIR)/ignite

$(BIN_DIR)/ignite: $(OBJ_DIR)/ignite.o $(OBJ_DIR)/main.o | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)/ignite.o: $(SRC_DIR)/ignite.cpp $(INC_DIR)/ignite.hpp $(INC_DIR)/aplib.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INC_DIR)/ignite.hpp $(INC_DIR)/aplib.hpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR):
	mkdir -p $@

$(BIN_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)
