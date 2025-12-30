/*
** EPITECH PROJECT, 2025
** around_tower
** File description:
** tower
*/

#include "../../include/my_radar.h"

void checker_placement(plane_stock_t *plane, tower_stock_t *tower)
{
    float plane_x = sfRectangleShape_getPosition(plane->hitbox).x;
    float plane_y = sfRectangleShape_getPosition(plane->hitbox).y;
    float tower_x = tower->pos.x;
    float tower_y = tower->pos.y;
    float dx = plane_x - tower_x;
    float dy = plane_y - tower_y;
    float distance = sqrt(dx * dx + dy * dy);

    if (distance <= tower->radius) {
        sfRectangleShape_setFillColor(plane->hitbox,
            (sfColor){255, 0, 0, 150});
        sfRectangleShape_setOutlineColor(plane->hitbox, sfRed);
    }
}

void check_plane_around_tower(plane_stock_t *plane, tower_stock_t *tower)
{
    for (plane_stock_t *tmp_plane = plane; tmp_plane;
        tmp_plane = tmp_plane->next) {
        if (!tmp_plane->active)
            continue;
        sfRectangleShape_setFillColor(tmp_plane->hitbox,
            (sfColor){255, 255, 255, 65});
        sfRectangleShape_setOutlineColor(tmp_plane->hitbox, sfWhite);
        for (tower_stock_t *tmp_tower = tower;
            tmp_tower; tmp_tower = tmp_tower->next) {
            checker_placement(tmp_plane, tmp_tower);
        }
    }
}
