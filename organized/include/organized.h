/*
** EPITECH PROJECT, 2025
** organized
** File description:
** organized
*/

#include "linked_list.h"
#include "shell.h"

#ifndef MY_ORGANIZED
    #define MY_ORGANIZED

typedef struct workshop_stock {
    int unique_id;
    char *type;
    char *name;
    int id_max;
} workshop_stock_t;

char *my_strdup(char *str);
int my_getnbr(char const *str);
linked_list_t *sorted_merge_name(linked_list_t *a, linked_list_t *b);
linked_list_t *sorted_merge_type(linked_list_t *a, linked_list_t *b);
linked_list_t *sorted_merge_id(linked_list_t *a, linked_list_t *b);
int my_wordarraylen(char **array);
int my_strcmp(char *s1, char *s2);
linked_list_t *choose_comparaison_reverse(linked_list_t *a,
    linked_list_t *b, char **argv);
linked_list_t *sorted_merge_name_reverse(linked_list_t *a, linked_list_t *b);
linked_list_t *sorted_merge_type_reverse(linked_list_t *a, linked_list_t *b);
linked_list_t *sorted_merge_id_reverse(linked_list_t *a, linked_list_t *b);
void my_putchar(char c);
void my_putstr(char *str);
void my_putnbr(int nb);
int is_valid_type(char *str);
int is_valid_sort(char *str);
#endif
