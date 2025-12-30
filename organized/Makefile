##
## EPITECH PROJECT, 2025
## makefile for printf
## File description:
## makefile for printf project 2025 epitech
##

NAME        = organized

RM          = rm -f

SRC         = $(shell find . -name "*.c" -not -path "./tests/*")
TEST_SRC    = $(shell find . -name "*.c" -not -path "./tests/*" -not -name "main.c")

OBJ         = $(SRC:.c=.o)

TEST_NAME   = organized

all: $(NAME)

$(NAME):
	make -C ./lib_linked_list
	epiclang $(SRC) -o $(NAME) -I./include -L./include -lshell -L./lib_linked_list -llinkedl

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	$(RM) units_test
	$(RM) *.gcda *.gcno

unit_tests: fclean
	make -C ./lib_linked_list
	clang -o units_test $(TEST_SRC) tests/*.c --coverage -lcriterion -lgcov -L./include -lshell -L./lib_linked_list -llinkedl -I./include

tests_run: unit_tests
	./units_test
	gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/

cover: tests_run
	gcovr --gcov-executable "llvm-cov-20 gcov" --exclude tests/ --branches

re: fclean all