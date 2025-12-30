/*
** EPITECH PROJECT, 2025
** created
** File description:
** circle
*/

#include "../../include/my_radar.h"

circle_stock_t *create_circle(circle_stock_t *circle,
    sfVector2f *pos_tower, int radius)
{
    circle_stock_t *new_circle = malloc(sizeof(circle_stock_t));
    int bigger_radius = radius * 4;

    if (!new_circle)
        return circle;
    new_circle->circle = sfCircleShape_create();
    sfCircleShape_setPosition(new_circle->circle, *pos_tower);
    sfCircleShape_setRadius(new_circle->circle, bigger_radius);
    sfCircleShape_setOrigin(new_circle->circle,
        (sfVector2f){bigger_radius, bigger_radius});
    sfCircleShape_setFillColor(new_circle->circle, (sfColor){0, 0, 0, 0});
    sfCircleShape_setOutlineColor(new_circle->circle, sfWhite);
    sfCircleShape_setOutlineThickness(new_circle->circle, 2);
    new_circle->show_circle = 1;
    new_circle->next = circle;
    return new_circle;
}

void draw_circle(sfRenderWindow *window, circle_stock_t *circle)
{
    for (circle_stock_t *tmp = circle; tmp; tmp = tmp->next) {
        if (tmp->show_circle)
            sfRenderWindow_drawCircleShape(window, tmp->circle, NULL);
    }
}

circle_stock_t *circle_init(char *argv, circle_stock_t **circle)
{
    int i = 0;
    char *circle_info = my_getinfo_t(my_getinfo(argv));
    sfVector2f pos_circle;
    int radius_circle;
    char **circle_info_word = my_str_to_word_array(circle_info);

    for (i = 0; circle_info_word[i] != NULL; i++) {
        pos_circle = my_getvector(circle_info_word[i]);
        *circle = create_circle(*circle,
            &(sfVector2f){pos_circle.x, pos_circle.y},
            my_getradius(circle_info_word[i],
                &(sfVector2f){pos_circle.x, pos_circle.y}));
    }
    return *circle;
}

void destroy_circles(circle_stock_t *circle)
{
    circle_stock_t *tmp;

    while (circle) {
        tmp = circle->next;
        sfCircleShape_destroy(circle->circle);
        free(circle);
        circle = tmp;
    }
}
