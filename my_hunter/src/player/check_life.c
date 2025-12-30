/*
** EPITECH PROJECT, 2025
** check_life
** File description:
** check_life
*/

#include "../../include/csfml.h"

game_state_t check_life(sfRenderWindow *window, sfEvent event, int life)
{
    if (life == 0) {
        return STATE_GAMEOVER;
    }
    return STATE_GAME;
}
