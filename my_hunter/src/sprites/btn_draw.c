/*
** EPITECH PROJECT, 2025
** draw_decor
** File description:
** draw_decor
*/

#include "../../include/csfml.h"

stock_btn_t *add_btn(stock_btn_t *head, const char *path,
    sfVector2f *scale, sfVector2f *pos)
{
    stock_btn_t *new = malloc(sizeof(stock_btn_t));

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
    new->position = sfSprite_getPosition(new->sprite);
    new->next = head;
    return new;
}

void destroy_btn(stock_btn_t *head)
{
    stock_btn_t *tmp;

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

void draw_btn(sfRenderWindow *window, stock_btn_t *head)
{
    for (stock_btn_t *tmp = head; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}
