/*
** EPITECH PROJECT, 2025
** del
** File description:
** delete item from list
*/

#include "../../include/organized.h"

void print_info(workshop_stock_t *item)
{
    my_putstr(item->type ? item->type : "NULL");
    my_putstr(" n°");
    my_putnbr(item->unique_id);
    my_putstr(" - \"");
    my_putstr(item->name ? item->name : "NULL");
    my_putstr("\" deleted.\n");
}

int delete_id(void *data, char **args, int i)
{
    linked_list_t **stock = (linked_list_t **)data;
    linked_list_t *list = *stock;
    workshop_stock_t *item;

    if (args[i] == NULL)
        return 84;
    for (linked_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp->data == NULL)
            break;
        item = (workshop_stock_t *)tmp->data;
        if (item->unique_id == my_getnbr(args[i])) {
            print_info(item);
            delete_in_list(stock, &item->unique_id);
        }
    }
    return 0;
}

int is_id_exist(void *data, char **args, int i)
{
    linked_list_t **stock = (linked_list_t **)data;
    linked_list_t *list = *stock;
    workshop_stock_t *item;

    if (args[i] == NULL)
        return 1;
    for (linked_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp->data == NULL)
            break;
        item = (workshop_stock_t *)tmp->data;
        if (item->unique_id == my_getnbr(args[i]))
            return 0;
    }
    return 1;
}

int del(void *data, char **args)
{
    int i = 0;
    int value_r;

    if (!args[0])
        return 84;
    for (i = 0; args[i] != NULL; i++) {
        if (is_id_exist(data, args, i) == 1)
            return 84;
        value_r = delete_id(data, args, i);
    }
    return value_r;
}
