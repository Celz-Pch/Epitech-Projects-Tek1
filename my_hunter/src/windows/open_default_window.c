/*
** EPITECH PROJECT, 2025
** open_default_windows
** File description:
** open_default_windows
*/

#include "../../include/csfml.h"

void open_default_windows(sfRenderWindow *window, sfEvent event,
    stock_decor_t *decor, stock_btn_t *btn)
{
    game_state_t state = STATE_MENU;

    while (sfRenderWindow_isOpen(window) && state == STATE_MENU) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            close_windows(window, event);
            state = button_play_pressed(window, event, btn);
        }
        sfRenderWindow_clear(window, sfWhite);
        draw_decor(window, decor);
        draw_btn(window, btn);
        sfRenderWindow_display(window);
    }
    if (state == STATE_GAME) {
        open_game_windows(window, event, decor, btn);
    }
}
