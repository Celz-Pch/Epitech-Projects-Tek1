/*
** EPITECH PROJECT, 2025
** my_get_speed
** File description:
** in pixel per seconda
*/

#include "../../include/my_radar.h"

int calculate_place_speed(char *file, int end)
{
    int i = end;

    for (; file[i] != ' '; i--);
    i--;
    for (; file[i] != ' '; i--);
    return i;
}

float my_get_speed(char *file)
{
    int len = my_strlen(file);
    int less_count = calculate_place_speed(file, len);

    return my_getnbr(file + less_count);
}
