/*
** EPITECH PROJECT, 2025
** destroy
** File description:
** destroy
*/

#include "../../include/csfml.h"

void destroy_enemy(stock_enemy_t *head)
{
    stock_enemy_t *tmp;

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

static int is_white(const sfColor *c)
{
    return (c->r >= 230 && c->g >= 230 && c->b >= 230);
}

static int is_red(const sfColor *c)
{
    return (c->r >= 230 && c->r <= 255 &&
        c->g >= 0 && c->g <= 60 &&
        c->b >= 0 && c->b <= 60);
}

void choose_color(sfImage *image, unsigned int x, unsigned int y)
{
    sfColor c = sfImage_getPixel(image, x, y);

    if (is_white(&c)) {
        sfImage_setPixel(image, x, y, sfColor_fromRGBA(242, 30, 44,
                c.a));
    }
    if (is_red(&c)) {
        sfImage_setPixel(image, x, y, sfColor_fromRGBA(255, 255, 255,
                c.a));
    }
}

void swap_color(sfImage *image)
{
    sfVector2u size = sfImage_getSize(image);
    sfColor c;

    for (unsigned int y = 0; y < size.y; ++y) {
        for (unsigned int x = 0; x < size.x; ++x) {
            choose_color(image, x, y);
        }
    }
}

void update_enemy_color(stock_enemy_t *head)
{
    sfTime t;
    float sec;

    for (stock_enemy_t *tmp = head; tmp != NULL; tmp = tmp->next) {
        t = sfClock_getElapsedTime(tmp->clock);
        sec = sfTime_asSeconds(t);
        if (sec >= tmp->change_delay) {
            swap_color(tmp->image);
            sfTexture_destroy(tmp->texture);
            tmp->texture = sfTexture_createFromImage(tmp->image, NULL);
            sfSprite_setTexture(tmp->sprite, tmp->texture, sfTrue);
            sfClock_restart(tmp->clock);
        }
    }
}

void draw_enemy(sfRenderWindow *window, stock_enemy_t *head)
{
    for (stock_enemy_t *tmp = head; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
    }
}
