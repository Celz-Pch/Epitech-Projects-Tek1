/*
** EPITECH PROJECT, 2025
** check_life
** File description:
** check_life
*/

#include "../../include/csfml.h"

void draw_life(sfRenderWindow *window, int life, const char *path)
{
    int old_life = -1;
    sfTexture *texture = NULL;
    sfSprite *sprite = NULL;

    if (texture == NULL || life != old_life) {
        if (texture)
            sfTexture_destroy(texture);
        texture = sfTexture_createFromFile(path, NULL);
        old_life = life;
    }
    if (sprite == NULL) {
        sprite = sfSprite_create();
        sfSprite_setScale(sprite, (sfVector2f){2.5f, 2.5f});
        sfSprite_setPosition(sprite, (sfVector2f){20.f, 20.f});
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void draw_health(sfRenderWindow *window, int life)
{
    const char *path = "./assets/health3.png";

    if (life == 1)
        path = "./assets/health1.png";
    if (life == 2)
        path = "./assets/health2.png";
    if (life == 3)
        path = "./assets/health3.png";
    draw_life(window, life, path);
}
