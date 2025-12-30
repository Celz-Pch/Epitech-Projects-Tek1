/*
** EPITECH PROJECT, 2025
** move
** File description:
** plane
*/

#include "../../include/my_radar.h"

void remove_plane(plane_stock_t *prev,
    plane_stock_t **plane, plane_stock_t *tmp)
{
    if (prev == NULL) {
        *plane = tmp->next;
    } else {
        prev->next = tmp->next;
    }
    sfSprite_destroy(tmp->sprite);
    sfTexture_destroy(tmp->texture);
    sfRectangleShape_destroy(tmp->hitbox);
    free(tmp);
    return;
}

void find_remove_plane(plane_stock_t **plane, plane_stock_t *to_remove)
{
    plane_stock_t *tmp = *plane;
    plane_stock_t *prev = NULL;

    while (tmp) {
        if (tmp == to_remove) {
            remove_plane(prev, plane, tmp);
            return;
        }
        prev = tmp;
        tmp = tmp->next;
    }
}

void verif_dist_plane(float distance, sfVector2f *direction,
    plane_stock_t *tmp, plane_stock_t **plane)
{
    float angle;
    float speed;

    if (distance > 0) {
        direction->x = (direction->x / distance) * (tmp->speed / 50);
        direction->y = (direction->y / distance) * (tmp->speed / 50);
        angle = atan2(direction->y, direction->x) * 180 / 3.14;
        sfSprite_setRotation(tmp->sprite, angle);
        sfRectangleShape_setRotation(tmp->hitbox, angle);
        sfSprite_move(tmp->sprite, *direction);
        sfRectangleShape_move(tmp->hitbox, *direction);
    }
    if (distance < 5.0f) {
        find_remove_plane(plane, tmp);
    }
}

void move_plane(plane_stock_t **plane)
{
    sfVector2f current_pos;
    sfVector2f direction;
    float distance;
    plane_stock_t *tmp;
    plane_stock_t *next;

    tmp = *plane;
    while (tmp) {
        next = tmp->next;
        if (tmp->active) {
            current_pos = sfRectangleShape_getPosition(tmp->hitbox);
            direction = (sfVector2f){tmp->pos_arrival.x - current_pos.x,
                tmp->pos_arrival.y - current_pos.y};
            distance = sqrt(direction.x * direction.x +
                direction.y * direction.y);
            verif_dist_plane(distance, &direction, tmp, plane);
        }
        tmp = next;
    }
}

void activate_planes(plane_stock_t *plane, sfClock *clock)
{
    float elapsed = sfTime_asSeconds(sfClock_getElapsedTime(clock));

    for (plane_stock_t *tmp = plane; tmp; tmp = tmp->next) {
        if (!tmp->active && elapsed >= tmp->delay)
            tmp->active = sfTrue;
    }
}
