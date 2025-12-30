/*
** EPITECH PROJECT, 2025
** created
** File description:
** tower
*/

#include "../../include/my_radar.h"


tower_stock_t *create_tower(tower_stock_t *tower, sfVector2f *pos_tower,
    int radius)
{
    tower_stock_t *new_tower = malloc(sizeof(tower_stock_t));

    if (!new_tower)
        return tower;
    new_tower->texture = sfTexture_createFromFile("./assets/tower.png", NULL);
    new_tower->sprite = sfSprite_create();
    new_tower->radius = radius * 4;
    new_tower->pos = *pos_tower;
    sfSprite_setTexture(new_tower->sprite, new_tower->texture, sfTrue);
    sfSprite_setPosition(new_tower->sprite,
        (sfVector2f){pos_tower->x - (51 / 2), pos_tower->y - (51 / 2)});
    new_tower->show_sprite = 1;
    new_tower->next = tower;
    return new_tower;
}

void draw_tower(sfRenderWindow *window, tower_stock_t *tower)
{
    for (tower_stock_t *tmp = tower; tmp; tmp = tmp->next) {
        if (tmp->show_sprite)
            sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
    }
}

tower_stock_t *tower_init(char *argv, tower_stock_t **tower)
{
    int i = 0;
    char *tower_info = my_getinfo_t(my_getinfo(argv));
    sfVector2f pos_tower;
    int radius_circle;
    char **tower_info_word = my_str_to_word_array(tower_info);

    for (i = 0; tower_info_word[i] != NULL; i++) {
        pos_tower = my_getvector(tower_info_word[i]);
        *tower = create_tower(*tower, &(sfVector2f){pos_tower.x, pos_tower.y},
            my_getradius(tower_info_word[i],
                &(sfVector2f){pos_tower.x, pos_tower.y}));
    }
    return *tower;
}

void destroy_towers(tower_stock_t *tower)
{
    tower_stock_t *tmp;

    while (tower) {
        tmp = tower->next;
        sfSprite_destroy(tower->sprite);
        sfTexture_destroy(tower->texture);
        free(tower);
        tower = tmp;
    }
}
