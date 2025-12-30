##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

NAME	= csfml

RM	= rm -f

OBJ	= $(SRC:.c=.o)

TEST_NAME = my_hunter

all: $(NAME)

$(NAME):
	epiclang src/hand/*.c src/music/*.c src/menu/*.c src/*.c src/windows/*.c src/sprites/*.c src/function/*.c src/button/*.c src/animation/*.c src/weapon/*.c src/enemy/*.c src/player/*.c -o $(TEST_NAME) -I./include -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm

compile:
	epiclang src/my_ls.c -o $(TEST_NAME) -I./include -L./lib/my -lmy

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) units_test
	$(RM) *.gcda *.gcno

re: fclean all
