/*
** EPITECH PROJECT, 2025
** my_print
** File description:
** print functions using write
*/

#include "../../include/organized.h"
#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    if (str == NULL)
        return;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb >= 10)
        my_putnbr(nb / 10);
    my_putchar((nb % 10) + '0');
}
