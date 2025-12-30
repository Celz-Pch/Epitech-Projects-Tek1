/*
** EPITECH PROJECT, 2025
** background
** File description:
** background
*/

#include "../../include/my_radar.h"

background_t *created_background(background_t *background)
{
    background_t *new_background = malloc(sizeof(background_t));

    if (!new_background)
        return background;
    new_background->texture = sfTexture_createFromFile(
        "./assets/map.png", NULL);
    if (!new_background->texture) {
        free(new_background);
        return background;
    }
    new_background->sprite = sfSprite_create();
    sfSprite_setTexture(new_background->sprite,
        new_background->texture, sfTrue);
    new_background->next = background;
    return new_background;
}

void draw_background(sfRenderWindow *window, background_t *background)
{
    if (!window || !background)
        return;
    for (background_t *tmp = background; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
    }
}

void destroy_background(background_t *background)
{
    background_t *tmp;

    while (background) {
        tmp = background->next;
        sfSprite_destroy(background->sprite);
        sfTexture_destroy(background->texture);
        free(background);
        background = tmp;
    }
}
