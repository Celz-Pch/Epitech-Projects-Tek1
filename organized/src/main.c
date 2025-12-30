/*
** EPITECH PROJECT, 2025
** main
** File description:
** main
*/

#include "../include/organized.h"

int main(void)
{
    linked_list_t *begin = malloc(sizeof(linked_list_t));
    workshop_stock_t meta_d = {0, NULL, NULL, 0};
    int value_r;

    if (!begin)
        return 84;
    begin->data = &meta_d;
    begin->next = NULL;
    value_r = workshop_shell(begin);
    return value_r;
}
