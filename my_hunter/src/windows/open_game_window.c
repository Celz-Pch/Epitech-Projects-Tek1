/*
** EPITECH PROJECT, 2025
** open window game
** File description:
** game windows
*/

#include "../../include/csfml.h"

static game_state2_t *init_game_state(void)
{
    game_state2_t *state = malloc(sizeof(game_state2_t));

    state->spawn_clock = sfClock_create();
    state->spawn_clown_clock = sfClock_create();
    state->delta_clock = sfClock_create();
    state->menu = NULL;
    state->enemy = NULL;
    state->my_anim = NULL;
    state->hand = NULL;
    state->music = init_game_music();
    srand(time(NULL));
    state->enemy = init_enemy(3, state->enemy);
    state->life = 3;
    state->score = 0;
    state->hand = create_animated_hand("./assets/hand.png", 5, 0, state->hand);
    return state;
}

static void handle_game_events(sfRenderWindow *window, sfEvent event,
    game_state2_t *state)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        close_windows(window, event);
        state->menu = menu_pause(window, event, state->menu);
        if (state->menu)
            menu_button_pressed(window, event, state->menu);
        check_kill_enemy(window, event, &state->enemy, state);
        check_kill_anim(window, event, &state->my_anim, state);
    }
}

static void update_game_logic(sfRenderWindow *window,
    game_state2_t *state, float delta_time)
{
    update_enemy_position(state->enemy, delta_time);
    update_animations(state->my_anim);
    update_positions(state->my_anim, delta_time);
    state->enemy = remove_offscreen_enemies(state->enemy, state);
    update_hand_frame(window, state->hand);
}

static void spawn_clown(game_state2_t *state)
{
    float time = 3.0;

    if (state->score > 25)
        time = 1;
    if (sfTime_asSeconds(sfClock_getElapsedTime(
                state->spawn_clown_clock)) > time) {
        state->my_anim = create_animated_sprite("./assets/clown.png",
            4, 0.2, state->my_anim);
        sfClock_restart(state->spawn_clown_clock);
    }
}

static void spawn_hand(game_state2_t *state)
{
    state->hand = create_animated_hand("./assets/hand.png",
        5, 0, state->hand);
}

static void spawn_enemies(game_state2_t *state)
{
    int choix;
    int random_x;
    float time = 1.5;

    if (state->score > 25)
        time = 1;
    if (sfTime_asSeconds(sfClock_getElapsedTime(state->spawn_clock)) > time) {
        choix = rand() % 2;
        random_x = (choix == 0) ? -200 : 1850;
        state->enemy = add_enemy(state->enemy, "./assets/cible.png",
            &(sfVector2f){0.25, 0.25}, &(sfVector2f){random_x, 850});
        sfClock_restart(state->spawn_clock);
    }
}

static void render_game(sfRenderWindow *window, stock_decor_t *decor,
    game_state2_t *state)
{
    sfRenderWindow_clear(window, sfBlack);
    draw_decor(window, decor);
    if (!state->menu)
        update_enemy_color(state->enemy);
    set_cursor(window);
    draw_enemy(window, state->enemy);
    draw_hand(window, state->hand);
    draw_menu(window, state->menu);
    draw_health(window, state->life);
    draw_animation(window, state->my_anim);
    draw_score(window, state->score);
    sfRenderWindow_display(window);
}

static void cleanup_game_state(game_state2_t *state)
{
    destroy_enemy(state->enemy);
    if (state->music) {
        sfMusic_stop(state->music);
        sfMusic_destroy(state->music);
    }
    sfClock_destroy(state->spawn_clock);
    sfClock_destroy(state->delta_clock);
    save_score(state->score);
    free(state);
}

void open_game_windows(sfRenderWindow *window, sfEvent event,
    stock_decor_t *decor, stock_btn_t *btn)
{
    game_state2_t *state = init_game_state();
    float delta_time;
    game_state_t in_state = STATE_GAME;

    sfRenderWindow_setFramerateLimit(window, 120);
    while (sfRenderWindow_isOpen(window) && in_state == STATE_GAME) {
        delta_time = sfTime_asSeconds(
            sfClock_restart(state->delta_clock));
        handle_game_events(window, event, state);
        if (!state->menu) {
            update_game_logic(window, state, delta_time);
            spawn_enemies(state);
            spawn_clown(state);
            in_state = check_life(window, event, state->life);
        }
        render_game(window, decor, state);
    }
    cleanup_game_state(state);
    if (in_state == STATE_GAMEOVER)
        open_gameove_window(window, event, state);
}
