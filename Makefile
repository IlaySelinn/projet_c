SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

CC := gcc

# Derleme ayarları
CFLAGS := -std=c99 -Wall -Wextra -Werror -Isrc

# Kaynak ve objeler
SRC := $(wildcard $(SRC_DIR)/*.c $(SRC_DIR)/**/*.c)
OBJ := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
OUT := clay

all: build

$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

build: $(OBJ)
	$(CC) $^ -o $(OUT)

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)
       


