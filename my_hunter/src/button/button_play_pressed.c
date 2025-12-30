/*
** EPITECH PROJECT, 2025
** button just pressed
** File description:
** btn jt pr
*/

#include "../../include/csfml.h"

game_state_t button_play_pressed(sfRenderWindow *window, sfEvent event,
    stock_btn_t *btn)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds;

    if (event.type != sfEvtMouseButtonPressed)
        return STATE_MENU;
    for (stock_btn_t *tmp = btn; tmp != NULL; tmp = tmp->next) {
        bounds = sfSprite_getGlobalBounds(tmp->sprite);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            return STATE_GAME;
        }
    }
    return STATE_MENU;
}
