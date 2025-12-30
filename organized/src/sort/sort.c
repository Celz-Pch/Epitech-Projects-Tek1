/*
** EPITECH PROJECT, 2025
** sort
** File description:
** sort
*/

#include "../../include/organized.h"

linked_list_t *choose_comparaison(linked_list_t *a,
    linked_list_t *b, char **argv)
{
    if (argv[1] != NULL && my_strcmp("-r", argv[1]) == 0) {
        return choose_comparaison_reverse(a, b, argv);
    } else {
        if (my_strcmp(argv[0], "NAME") == 0)
            return sorted_merge_name(a, b);
        if (my_strcmp(argv[0], "TYPE") == 0)
            return sorted_merge_type(a, b);
        if (my_strcmp(argv[0], "ID") == 0)
            return sorted_merge_id(a, b);
    }
    return a;
}

void slipt_push(linked_list_t *source,
    linked_list_t **frontRef, linked_list_t **backRef)
{
    linked_list_t *slow;
    linked_list_t *fast;

    if (source == NULL || source->next == NULL) {
        *frontRef = source;
        *backRef = NULL;
        return;
    }
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

linked_list_t *merge_sort(linked_list_t *head, char **argv)
{
    linked_list_t *a = NULL;
    linked_list_t *b = NULL;

    if (head == NULL || head->next == NULL)
        return head;
    slipt_push(head, &a, &b);
    a = merge_sort(a, argv);
    b = merge_sort(b, argv);
    return choose_comparaison(a, b, argv);
}

int sort(void *data, char **argv)
{
    linked_list_t **workshop_stock = (linked_list_t **)data;

    if (!argv[0])
        return 84;
    if (workshop_stock == NULL || *workshop_stock == NULL)
        return 0;
    if (is_valid_sort(argv[0]) == 1)
        return 84;
    if (my_wordarraylen(argv) >= 1)
        *workshop_stock = merge_sort(*workshop_stock, argv);
    return 0;
}
