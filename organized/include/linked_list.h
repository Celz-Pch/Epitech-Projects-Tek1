/*
** EPITECH PROJECT, 2025
** linked
** File description:
** linked_list
*/

#include <stdlib.h>
#include <stdio.h>

#ifndef LINKED_LIB
    #define LINKED_LIB

typedef struct linked_list_s {
    void *data;
    struct linked_list_s *next;
} linked_list_t;

void delete_in_list(linked_list_t **begin, void const *ref);
void disp_list(linked_list_t **begin);
void push_to_list(linked_list_t **begin, void *data);
#endif
