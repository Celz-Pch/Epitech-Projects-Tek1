/*
** EPITECH PROJECT, 2025
** delete_in_list
** File description:
** delete_in_list
*/

#include "../include/linked_list.h"

void delete_in_list(linked_list_t **begin, void const *ref)
{
    linked_list_t **workshop_stock = begin;

    while (workshop_stock != NULL) {
        if (*(int *)(*workshop_stock)->data == *(int *)ref &&
            (*workshop_stock)->next == NULL) {
            (*workshop_stock) = NULL;
            break;
        }
        if (*(int *)(*workshop_stock)->data == *(int *)ref) {
            (*workshop_stock) = (*workshop_stock)->next;
            break;
        }
        if ((*workshop_stock)->next == NULL)
            break;
        workshop_stock = &(*workshop_stock)->next;
    }
}
