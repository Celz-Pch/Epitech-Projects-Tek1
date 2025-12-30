/*
** EPITECH PROJECT, 2025
** reverse
** File description:
** sort
*/

#include "../../include/organized.h"

linked_list_t *choose_comparaison_reverse(linked_list_t *a,
    linked_list_t *b, char **argv)
{
    if (my_strcmp(argv[0], "NAME") == 0)
        return sorted_merge_name_reverse(a, b);
    if (my_strcmp(argv[0], "TYPE") == 0)
        return sorted_merge_type_reverse(a, b);
    if (my_strcmp(argv[0], "ID") == 0)
        return sorted_merge_id_reverse(a, b);
    return a;
}

linked_list_t *sorted_merge_name_reverse(linked_list_t *a, linked_list_t *b)
{
    workshop_stock_t *item1;
    workshop_stock_t *item2;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->data == NULL || b->data == NULL)
        return a;
    item1 = (workshop_stock_t *)a->data;
    item2 = (workshop_stock_t *)b->data;
    if (my_strcmp(item1->name, item2->name) > 0) {
        a->next = sorted_merge_name_reverse(a->next, b);
        return a;
    } else {
        b->next = sorted_merge_name_reverse(a, b->next);
        return b;
    }
}

linked_list_t *sorted_merge_type_reverse(linked_list_t *a, linked_list_t *b)
{
    workshop_stock_t *item1;
    workshop_stock_t *item2;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->data == NULL || b->data == NULL)
        return a;
    item1 = (workshop_stock_t *)a->data;
    item2 = (workshop_stock_t *)b->data;
    if (my_strcmp(item1->type, item2->type) > 0) {
        a->next = sorted_merge_type_reverse(a->next, b);
        return a;
    } else {
        b->next = sorted_merge_type_reverse(a, b->next);
        return b;
    }
}

linked_list_t *sorted_merge_id_reverse(linked_list_t *a, linked_list_t *b)
{
    workshop_stock_t *item1;
    workshop_stock_t *item2;

    if (a == NULL)
        return b;
    if (b == NULL)
        return a;
    if (a->data == NULL || b->data == NULL)
        return a;
    item1 = (workshop_stock_t *)a->data;
    item2 = (workshop_stock_t *)b->data;
    if (item1->unique_id > item2->unique_id) {
        a->next = sorted_merge_id_reverse(a->next, b);
        return a;
    } else {
        b->next = sorted_merge_id_reverse(a, b->next);
        return b;
    }
}
