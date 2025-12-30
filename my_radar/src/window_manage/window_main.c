/*
** EPITECH PROJECT, 2025
** window
** File description:
** main
*/

#include "../../include/my_radar.h"

static void toggle_hitbox_circle(plane_stock_t *plane, circle_stock_t *circle)
{
    for (plane_stock_t *tmp = plane; tmp; tmp = tmp->next)
        tmp->show_hitbox = !tmp->show_hitbox;
    for (circle_stock_t *tmp = circle; tmp; tmp = tmp->next)
        tmp->show_circle = !tmp->show_circle;
}

static void toggle_sprites(plane_stock_t *plane, tower_stock_t *tower)
{
    for (plane_stock_t *tmp = plane; tmp; tmp = tmp->next)
        tmp->show_sprite = !tmp->show_sprite;
    for (tower_stock_t *tmp = tower; tmp; tmp = tmp->next)
        tmp->show_sprite = !tmp->show_sprite;
}

static void event_use(game_stock_t *game)
{
    while (sfRenderWindow_pollEvent(game->window, &game->event)) {
        if (game->event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
        if (game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyL)
            toggle_hitbox_circle(game->plane, game->circle);
        if (game->event.type == sfEvtKeyPressed &&
            game->event.key.code == sfKeyS)
            toggle_sprites(game->plane, game->tower);
    }
}

void draw_all(game_stock_t *game)
{
    draw_tower(game->window, game->tower);
    draw_circle(game->window, game->circle);
    draw_hitbox(game->window, game->plane);
    draw_plane(game->window, game->plane);
}

static int count_active_planes(plane_stock_t *plane)
{
    int count = 0;

    while (plane != NULL) {
        if (plane->active == sfTrue || plane->delay > 0)
            count++;
        plane = plane->next;
    }
    return count;
}

void plane_check_game(game_stock_t *game, sfClock *clock)
{
    move_plane(&game->plane);
    create_timer(game->window, clock);
    check_colision_plane(&game->plane);
    if (count_active_planes(game->plane) == 0)
        sfRenderWindow_close(game->window);
}

static void start_draw(game_stock_t *game, sfClock *clock)
{
    draw_background(game->window, game->background);
    activate_planes(game->plane, clock);
}

void destroy_planes(plane_stock_t *plane)
{
    plane_stock_t *tmp;

    while (plane) {
        tmp = plane->next;
        sfSprite_destroy(plane->sprite);
        sfTexture_destroy(plane->texture);
        sfRectangleShape_destroy(plane->hitbox);
        free(plane);
        plane = tmp;
    }
}

void destroy_game(game_stock_t *game, sfClock *clock)
{
    destroy_planes(game->plane);
    destroy_towers(game->tower);
    destroy_circles(game->circle);
    destroy_background(game->background);
    sfClock_destroy(clock);
    sfRenderWindow_destroy(game->window);
}

void open_start_window(sfRenderWindow *window, sfEvent event,
    corner_t corners[4], char *file)
{
    game_stock_t game = {window, event, NULL, NULL, NULL, NULL};
    sfClock *clock = sfClock_create();

    game.plane = plane_init(file, &game.plane);
    game.background = created_background(game.background);
    game.tower = tower_init(file, &game.tower);
    game.circle = circle_init(file, &game.circle);
    while (sfRenderWindow_isOpen(window)) {
        event_use(&game);
        sfRenderWindow_clear(window, (sfColor){0, 0, 0, 1});
        draw_rect(window, corners);
        start_draw(&game, clock);
        check_plane_around_tower(game.plane, game.tower);
        draw_all(&game);
        plane_check_game(&game, clock);
        sfRenderWindow_display(window);
    }
    destroy_game(&game, clock);
}
