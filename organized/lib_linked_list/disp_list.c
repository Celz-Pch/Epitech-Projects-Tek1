/*
** EPITECH PROJECT, 2025
** disp_list
** File description:
** disp_lsit
*/

#include "../include/linked_list.h"
#include <unistd.h>

static void my_putnbr_local(int nb)
{
    char c;

    if (nb < 0) {
        write(1, "-", 1);
        nb = -nb;
    }
    if (nb >= 10)
        my_putnbr_local(nb / 10);
    c = (nb % 10) + '0';
    write(1, &c, 1);
}

void disp_list(linked_list_t **begin)
{
    linked_list_t *tmp = *begin;

    while (tmp != NULL) {
        my_putnbr_local(*((int *)tmp->data));
        write(1, "  ", 2);
        tmp = tmp->next;
    }
}
