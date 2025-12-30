/*
** EPITECH PROJECT, 2025
** draw
** File description:
** rect
*/

#include "../../include/my_radar.h"

void draw_rect(sfRenderWindow *window, corner_t corners[4])
{
    sfRectangleShape *rectangle = sfRectangleShape_create();

    for (int i = 0; i < 4; i++) {
        sfRectangleShape_setPosition(rectangle,
            (sfVector2f){corners[i].corners.left, corners[i].corners.top});
        sfRectangleShape_setSize(rectangle,
            (sfVector2f){corners[i].corners.width, corners[i].corners.height});
        sfRectangleShape_setFillColor(rectangle, sfTransparent);
        sfRectangleShape_setOutlineThickness(rectangle, 2);
        sfRenderWindow_drawRectangleShape(window, rectangle, NULL);
    }
    sfRectangleShape_destroy(rectangle);
}
