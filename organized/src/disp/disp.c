/*
** EPITECH PROJECT, 2025
** disp
** File description:
** display list
*/

#include "../../include/organized.h"

void print_disp(workshop_stock_t *item)
{
    my_putstr(item->type ? item->type : "NULL");
    my_putstr(" n\xc2\xb0");
    my_putnbr(item->unique_id);
    my_putstr(" - \"");
    my_putstr(item->name ? item->name : "NULL");
    my_putstr("\"\n");
}

int disp(void *data, char **args)
{
    linked_list_t **stock_list = (linked_list_t **)data;
    linked_list_t *list = *stock_list;
    workshop_stock_t *item;

    if (list == NULL)
        return 84;
    for (linked_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp->data == NULL)
            break;
        item = (workshop_stock_t *)tmp->data;
        print_disp(item);
    }
    return 0;
}
