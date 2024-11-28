##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile with the folling rules: re, clean and fclean rules
##

CC = gcc

SRC = src/main.c \
	src/manage_events.c \
	src/manage_sprite.c \
	src/terminate.c \
	src/extra_features.c \
	src/scale_handling.c \
	src/lib/my_putstr.c \
	src/lib/my_strcmp.c \
	src/lib/my_putchar.c \
	src/lib/my_strcpy.c \
	src/lib/my_strcat.c

OBJ = $(SRC:.c=.o)

NAME = my_hunter

LDFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

$(NAME): $(OBJ)
	$(CC)	-o	$(NAME)	$(OBJ)	$(LDFLAGS)	-g

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
