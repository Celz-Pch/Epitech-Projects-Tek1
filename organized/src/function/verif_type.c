/*
** EPITECH PROJECT, 2025
** verif
** File description:
** type
*/

#include "../include/organized.h"

int is_valid_type(char *str)
{
    if (my_strcmp(str, "ACTUATOR") == 0)
        return 0;
    if (my_strcmp(str, "DEVICE") == 0)
        return 0;
    if (my_strcmp(str, "PROCESSOR") == 0)
        return 0;
    if (my_strcmp(str, "SENSOR") == 0)
        return 0;
    if (my_strcmp(str, "WIRE") == 0)
        return 0;
    return 1;
}

int is_valid_sort(char *str)
{
    if (my_strcmp(str, "NAME") == 0)
        return 0;
    if (my_strcmp(str, "TYPE") == 0)
        return 0;
    if (my_strcmp(str, "ID") == 0)
        return 0;
    return 1;
}
