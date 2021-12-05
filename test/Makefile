NAME = test
BUILD_DIR = build
CC = gcc

# These flags are strict to keep the library portable
# You should define your own flags depending on your platform
CFLAGS = -Wall -Wextra -Werror -std=c99 -pedantic

# Main test source file
SOURCES += main.c

# cboring sources
CBORING_ROOT = ..
CFLAGS += -I$(CBORING_ROOT)/src
VPATH += $(CBORING_ROOT)/src
SOURCES += $(notdir $(wildcard $(CBORING_ROOT)/src/*.c))

# Test application depends on these external libraries
UNITY_PATH ?=

CFLAGS += -Idependencies -Idependencies/$(UNITY_PATH)/src
VPATH += dependencies dependencies/$(UNITY_PATH)/src
SOURCES += unity.c decoding.c encoding.c

$(info $(SOURCES))

# Generate object files
OBJECTS += $(addprefix $(BUILD_DIR)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBS) -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(BUILD_DIR) $(NAME)
