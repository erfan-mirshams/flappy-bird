##
# flappy-bird
#
# @file
# @version 0.1
CFLAGS = -c -Wall -Wextra
LFLAGS = -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin

TARGET = flappy-bird

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES = $(addprefix $(BUILD_DIR)/, $(notdir $(SRC_FILES:.cpp=.o)))

$(BIN_DIR)/$(TARGET): $(OBJ_FILES)
	$(CXX) $(LFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -o $@ $<

clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)

# end
