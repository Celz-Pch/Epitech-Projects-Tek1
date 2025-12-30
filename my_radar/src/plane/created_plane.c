/*
** EPITECH PROJECT, 2025
** created
** File description:
** plane
*/

#include "../../include/my_radar.h"

void create_hitbox(plane_stock_t *new_plane)
{
    sfVector2f origin = {-3.5f, -3.5f};

    new_plane->hitbox = sfRectangleShape_create();
    sfRectangleShape_setSize(new_plane->hitbox, (sfVector2f){20, 20});
    sfRectangleShape_setOrigin(new_plane->hitbox, origin);
    sfRectangleShape_setPosition(new_plane->hitbox, new_plane->pos_departure);
    sfRectangleShape_setFillColor(new_plane->hitbox,
        (sfColor){255, 255, 255, 65});
    sfRectangleShape_setOutlineThickness(new_plane->hitbox, 1);
}

plane_stock_t *created_plane(plane_stock_t *plane, sfVector2f *pos_departure,
    sfVector2f *pos_arrival, sfVector2f *delay_speed)
{
    plane_stock_t *new_plane = malloc(sizeof(plane_stock_t));

    if (!new_plane)
        return plane;
    new_plane->texture = sfTexture_createFromFile("./assets/plane.png", NULL);
    new_plane->sprite = sfSprite_create();
    sfSprite_setTexture(new_plane->sprite, new_plane->texture, sfTrue);
    sfSprite_setPosition(new_plane->sprite, *pos_departure);
    new_plane->pos_departure = *pos_departure;
    new_plane->pos_arrival = *pos_arrival;
    new_plane->delay = delay_speed->x;
    new_plane->speed = delay_speed->y;
    new_plane->active = sfFalse;
    new_plane->show_sprite = 1;
    new_plane->show_hitbox = 1;
    create_hitbox(new_plane);
    new_plane->next = plane;
    return new_plane;
}

void draw_plane(sfRenderWindow *window, plane_stock_t *plane)
{
    for (plane_stock_t *tmp = plane; tmp; tmp = tmp->next)
        if (tmp->active && tmp->show_sprite)
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}

void draw_hitbox(sfRenderWindow *window, plane_stock_t *hitbox)
{
    for (plane_stock_t *tmp = hitbox; tmp; tmp = tmp->next)
        if (tmp->active && tmp->show_hitbox)
            sfRenderWindow_drawRectangleShape(window, tmp->hitbox, NULL);
}

plane_stock_t *plane_init(char *argv, plane_stock_t **plane)
{
    int i = 0;
    sfVector2f pos_departure;
    sfVector2f pos_arrival;
    char *plane_info = my_getinfo_a(my_getinfo(argv));
    char **tower_info_word = my_str_to_word_array(plane_info);
    sfVector2f send_delay_speed;

    for (i = 0; tower_info_word[i] != NULL; i++) {
        send_delay_speed.x = my_get_delay(tower_info_word[i]);
        send_delay_speed.y = my_get_speed(tower_info_word[i]);
        pos_departure = my_getvector(tower_info_word[i]);
        pos_arrival = my_getarrival_v(tower_info_word[i],
            &(sfVector2f){pos_departure.x, pos_departure.y});
        *plane = created_plane(*plane,
            &(sfVector2f){pos_departure.x, pos_departure.y},
            &(sfVector2f){pos_arrival.x, pos_arrival.y}, &send_delay_speed);
    }
    return *plane;
}
