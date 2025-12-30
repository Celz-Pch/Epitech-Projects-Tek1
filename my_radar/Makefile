##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

NAME	= csfml

RM	= rm -f

SRC = $(shell find . -name "*.c")

OBJ	= $(SRC:.c=.o)

TEST_NAME = my_radar

all: $(NAME)

$(NAME):
	epiclang $(SRC) -o $(TEST_NAME) -I./include -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio -lm -g3

valgrind:
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TEST_NAME) 2>&1 | tee valgrind_report.txt

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) units_test
	$(RM) *.gcda *.gcno

re: fclean all
