/*
** EPITECH PROJECT, 2025
** str$
** File description:
** dup
*/

#include "../../include/organized.h"

int my_wordarraylen(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return i;
}

int my_strlen_up(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

char *my_strdup(char *str)
{
    char *new_str = malloc(sizeof(char *) * (my_strlen_up(str) + 1));
    int i;

    for (i = 0; str[i] != '\0'; i++) {
        new_str[i] = str[i];
    }
    new_str[i] = '\0';
    return new_str;
}
