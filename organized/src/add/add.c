/*
** EPITECH PROJECT, 2025
** add
** File description:
** add item to list
*/

#include "../../include/organized.h"

void print_add(workshop_stock_t *item)
{
    my_putstr(item->type ? item->type : "NULL");
    my_putstr(" n\xc2\xb0");
    my_putnbr(item->unique_id);
    my_putstr(" - \"");
    my_putstr(item->name ? item->name : "NULL");
    my_putstr("\" added.\n");
}

static int get_next_id(linked_list_t *list)
{
    int max_id = -1;
    workshop_stock_t *item;

    for (linked_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (tmp->data == NULL)
            continue;
        item = tmp->data;
        if (item->unique_id > max_id)
            max_id = item->unique_id;
    }
    return max_id + 1;
}

int add_step(void *data, char **args, int i)
{
    linked_list_t **stock_list = (linked_list_t **)data;
    workshop_stock_t *item = malloc(sizeof(workshop_stock_t));

    if (!item || !args[i] || !args[i + 1])
        return 84;
    item->unique_id = get_next_id(*stock_list);
    item->type = my_strdup(args[i]);
    item->name = my_strdup(args[i + 1]);
    item->id_max = item->unique_id;
    push_to_list(stock_list, item);
    print_add(item);
    return 0;
}

int add(void *data, char **args)
{
    int i = 0;

    if (!args[0])
        return 84;
    for (i = 0; args[i] != NULL; i += 2) {
        if (!args[i] || !args[i + 1] || is_valid_type(args[i]) == 1)
            return 84;
        add_step(data, args, i);
    }
    return 0;
}
