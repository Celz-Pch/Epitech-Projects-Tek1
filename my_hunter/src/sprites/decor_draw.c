/*
** EPITECH PROJECT, 2025
** draw_decor
** File description:
** draw_decor
*/

#include "../../include/csfml.h"

stock_decor_t *add_decor(stock_decor_t *head, const char *path,
    sfVector2f *scale, sfVector2f *pos)
{
    stock_decor_t *new = malloc(sizeof(stock_decor_t));

    if (!new)
        return head;
    new->texture = sfTexture_createFromFile(path, NULL);
    if (!new->texture) {
        free(new);
        return head;
    }
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setScale(new->sprite, *scale);
    sfSprite_setPosition(new->sprite, *pos);
    new->next = head;
    return new;
}

void destroy_decor(stock_decor_t *head)
{
    stock_decor_t *tmp;

    while (head) {
        tmp = head->next;
        if (head->texture)
            sfTexture_destroy(head->texture);
        if (head->sprite)
            sfSprite_destroy(head->sprite);
        free(head);
        head = tmp;
    }
}

void draw_decor(sfRenderWindow *window, stock_decor_t *head)
{
    for (stock_decor_t *tmp = head; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}
