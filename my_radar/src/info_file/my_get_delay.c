/*
** EPITECH PROJECT, 2025
** get
** File description:
** delat
*/

#include "../../include/my_radar.h"

int my_strlen(char *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return i;
}

int calculate(char *file, int end)
{
    int i = end;

    for (; file[i] != ' '; i--);
    return i;
}

float my_get_delay(char *file)
{
    int len = my_strlen(file);
    int less_count = calculate(file, len);

    return my_getnbr(file + less_count);
}
