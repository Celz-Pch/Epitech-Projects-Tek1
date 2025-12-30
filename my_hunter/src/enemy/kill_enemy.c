/*
** EPITECH PROJECT, 2025
** kill
** File description:
** enemy
*/

#include "../../include/csfml.h"

void free_enemy(stock_enemy_t *tmp)
{
    if (tmp->texture)
        sfTexture_destroy(tmp->texture);
    if (tmp->sprite)
        sfSprite_destroy(tmp->sprite);
    free(tmp);
}

void remove_enemy(stock_enemy_t **enemy, stock_enemy_t *tmp,
    stock_enemy_t *prev, game_state2_t *state)
{
    if (prev)
        prev->next = tmp->next;
    else
        *enemy = tmp->next;
    free_enemy(tmp);
    state->score = state->score + 1;
}

void check_kill_enemy(sfRenderWindow *window, sfEvent event,
    stock_enemy_t **enemy, game_state2_t *state)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    stock_enemy_t *tmp = *enemy;
    stock_enemy_t *prev = NULL;
    stock_enemy_t *next;
    sfFloatRect bounds;

    if (event.type != sfEvtMouseButtonPressed)
        return;
    attack_song();
    while (tmp) {
        bounds = sfSprite_getGlobalBounds(tmp->sprite);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            next = tmp->next;
            remove_enemy(enemy, tmp, prev, state);
            tmp = next;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}
