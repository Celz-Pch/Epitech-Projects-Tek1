/*
** EPITECH PROJECT, 2025
** my_getinfoa
** File description:
** my_get_ginfo_a
*/

#include "../../include/my_radar.h"

int my_get_start_a(char *file)
{
    int i = 0;

    for (i = 0; file[i] != '\0'; i++) {
        if (file[i] == 'A')
            return i;
    }
    return 0;
}

int my_get_len_a(char *file)
{
    int count = 0;
    int count_a = 0;
    int i = 0;

    for (i = 0; file[i] != '\0'; i++) {
        if (file[i] == 'A')
            count_a = 1;
        if (count_a == 1)
            count++;
        if (file[i] == 'T')
            return count;
    }
    return count;
}

char *my_getinfo_a(char *file)
{
    int place = my_get_start_a(file);
    int count_a = my_get_len_a(file);
    char *stock_a = malloc(sizeof(char) * (count_a + 1));
    int i = 0;

    for (; file[place] != '\0'; place++) {
        stock_a[i] = file[place];
        i++;
        if (file[i] == 'T')
            break;
    }
    stock_a[i] = '\0';
    return stock_a;
}
