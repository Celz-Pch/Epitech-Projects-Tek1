/*
** EPITECH PROJECT, 2025
** push_to_list
** File description:
** push_to_list
*/

#include "../include/linked_list.h"

void push_to_list(linked_list_t **begin, void *data)
{
    linked_list_t *new_data = malloc(sizeof(linked_list_t));

    if (!new_data)
        return;
    new_data->data = data;
    new_data->next = *begin;
    *begin = new_data;
}
