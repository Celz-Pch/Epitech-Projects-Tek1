##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

NAME	= setting_up

RM	= rm -f

OBJ	= $(SRC:.c=.o)

TEST_NAME = setting_up

all: $(NAME)

$(NAME):
	make -C ./lib/my
	epiclang src/setting.c src/my_str_to_word_array.c src/get_count.c src/generation_map.c src/main.c -o $(TEST_NAME) -I ./include -L ./lib/my -lmy

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all