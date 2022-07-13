NAME = Cub3D

SRC = main.c
SRC_FOLDER =

SRC_PATH := $(foreach wrd,$(SRC),./src/$(wrd))\
			#$(foreach wrd,$(SRC_FOLDER),src/FOLDER/$(wrd))

LIB = ./libft/libft.a
LIB_DIR = ./libft

INCL = src/Cub3D.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address

all: $(NAME)

$(NAME): $(SRC_PATH) $(LIB) $(INCL)
	$(CC) $(CFLAGS) $(SRC_PATH) $(LIB) -o $(NAME)

test: $(SRC_PATH) $(LIB) $(INCL)
	$(CC) $(SRC_PATH) $(LIB) -o $(NAME)

$(LIB): $(LIB_DIR)
	make -C $(LIB_DIR)

clean:
	make -C $(LIB_DIR) clean

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME)

re: fclean all

