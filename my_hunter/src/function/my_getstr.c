/*
** EPITECH PROJECT, 2025
** my
** File description:
** getstr
*/

#include "../../include/csfml.h"

int my_strint(int number)
{
    int stock = number;
    int count = 0;

    while (stock > 0) {
        stock = stock / 10;
        count++;
    }
    return count;
}

char *int_to_str(int number)
{
    int len;
    int stock;
    char *res;

    if (number == 0) {
        res = malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    len = my_strint(number);
    res = malloc(len + 1);
    stock = number;
    for (int i = 0; i < len; i++) {
        res[len - 1 - i] = (stock % 10) + '0';
        stock = stock / 10;
    }
    res[len] = '\0';
    return res;
}
