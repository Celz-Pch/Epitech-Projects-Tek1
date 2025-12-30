/*
** EPITECH PROJECT, 2025
** open window game
** File description:
** game windows
*/

#include "../../include/csfml.h"

void open_gameove_window(sfRenderWindow *window,
    sfEvent event, game_state2_t *game)
{
    game_state_t state = STATE_GAMEOVER;
    stock_btn_t *btn = NULL;
    stock_decor_t *decor = NULL;

    btn = add_btn(btn, "./assets/play_btn.png",
        &(sfVector2f){0.25, 0.22}, &(sfVector2f){736.3f, 490});
    decor = add_decor(decor, "./assets/gameover.png",
        &(sfVector2f){1.22, 1}, &(sfVector2f){0.0f, 0.0f});
    while (sfRenderWindow_isOpen(window) && state == STATE_GAMEOVER) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            button_play_pressed(window, event, btn);
            close_windows(window, event);
        }
        sfRenderWindow_clear(window, sfWhite);
        draw_decor(window, decor);
        draw_btn(window, btn);
        sfRenderWindow_display(window);
    }
}
