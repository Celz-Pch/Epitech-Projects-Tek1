/*
** EPITECH PROJECT, 2025
** CSFML
** File description:
** CSFML header
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>

#ifndef CSFML_H
    #define CSFML_H

typedef struct stock_decor {
    sfSprite *sprite;
    sfTexture *texture;
    struct stock_decor *next;
} stock_decor_t;

typedef struct stock_btn {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    struct stock_btn *next;
} stock_btn_t;

typedef struct stock_menu {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    char *name;
    struct stock_menu *next;
} stock_menu_t;

typedef struct stock_enemy_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f position;
    float velocity_x;
    float velocity_y;
    int direction;
    sfImage *image;
    sfClock *clock;
    float change_delay;
    struct stock_enemy_s *next;
} stock_enemy_t;

typedef enum {
    STATE_MENU,
    STATE_GAME,
    STATE_GAMEOVER
} game_state_t;

typedef struct hand_sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfClock *hand_clock;
    int current_frame;
    int frame_count;
    float frame_duration;
    int frame_width;
    int frame_height;
    struct hand_sprite *next;
} hand_sprite_t;

typedef struct animated_sprite {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
    sfClock *anim_clock;
    int current_frame;
    int frame_count;
    int frame_width;
    int frame_height;
    float frame_duration;
    struct animated_sprite *next;
} animated_sprite_t;

typedef struct stock_weapon {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
} stock_weapon_t;

typedef struct stock_hand {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f position;
} stock_hand_t;

typedef struct projectile_s {
    sfSprite *sprite;
    sfVector2f position;
    sfVector2f target;
    sfVector2f velocity;
    int active;
    struct projectile_s *next;
} projectile_t;

typedef struct game_state2_s {
    sfClock *spawn_clock;
    sfClock *spawn_clown_clock;
    sfClock *delta_clock;
    stock_menu_t *menu;
    stock_enemy_t *enemy;
    animated_sprite_t *my_anim;
    hand_sprite_t *hand;
    sfMusic *music;
    int life;
    int score;
} game_state2_t;

void open_default_windows(sfRenderWindow *window, sfEvent event,
    stock_decor_t *decor, stock_btn_t *btn);
void close_windows(sfRenderWindow *window, sfEvent event);
game_state_t button_play_pressed(sfRenderWindow *window, sfEvent event,
    stock_btn_t *btn);
void destroy_all(stock_btn_t *btn, stock_decor_t *decor);
void open_game_windows(sfRenderWindow *window, sfEvent event,
    stock_decor_t *decor, stock_btn_t *btn);

// all decor func
stock_decor_t *add_decor(stock_decor_t *head, const char *path,
    sfVector2f *scale, sfVector2f *pos);
void destroy_decor(stock_decor_t *head);
void draw_decor(sfRenderWindow *window, stock_decor_t *head);

// all btn func
stock_btn_t *add_btn(stock_btn_t *head, const char *path,
    sfVector2f *scale, sfVector2f *pos);
void destroy_btn(stock_btn_t *head);
void draw_btn(sfRenderWindow *window, stock_btn_t *head);

//all menu func
stock_menu_t *add_menu(stock_menu_t *head, const char *path,
    sfVector2f *scale, sfVector2f *pos);
void draw_menu(sfRenderWindow *window, stock_menu_t *head);
void destroy_menu(stock_menu_t *head);

void check_kill_anim(sfRenderWindow *window, sfEvent event,
    animated_sprite_t **anim, game_state2_t *state);
animated_sprite_t *create_animated_sprite(const char *path, int frame_count,
    float frame_duration, animated_sprite_t *head);
void draw_animation(sfRenderWindow *window, animated_sprite_t *anim);
void update_animations(animated_sprite_t *list);
void update_positions(animated_sprite_t *anim_list, float delta_time);
void send_weapon(sfRenderWindow *window, sfEvent event,
    stock_weapon_t *weapon, projectile_t **projectiles);
void draw_weapon(sfRenderWindow *window, stock_weapon_t *head);
stock_weapon_t *add_weapon(const char *path,
    sfVector2f *scale, sfVector2f *pos);
stock_enemy_t *init_enemy(int count, stock_enemy_t *enemy);
void draw_enemy(sfRenderWindow *window, stock_enemy_t *head);
stock_enemy_t *remove_offscreen_enemies(stock_enemy_t *head,
    game_state2_t *state);
void update_enemy_position(stock_enemy_t *head, float delta_time);
stock_enemy_t *add_enemy(stock_enemy_t *head, const char *path,
    sfVector2f *scale, sfVector2f *pos);
void destroy_enemy(stock_enemy_t *head);
void destroy_projectiles(projectile_t *head);
void draw_projectiles(sfRenderWindow *window, projectile_t *head);
projectile_t *update_projectiles(projectile_t *head);
void check_kill_enemy(sfRenderWindow *window, sfEvent event,
    stock_enemy_t **enemy, game_state2_t *state);
game_state_t check_life(sfRenderWindow *window, sfEvent event,
    int life);
void draw_health(sfRenderWindow *window, int life);
void update_enemy_color(stock_enemy_t *head);
void set_cursor(sfRenderWindow *window);
stock_menu_t *menu_pause(sfRenderWindow *window, sfEvent event,
    stock_menu_t *menu);
sfMusic *init_game_music(void);
void open_gameove_window(sfRenderWindow *window, sfEvent event,
    game_state2_t *game);
char *getname(const char *name);
int my_strcmp(char const *s1, char const *s2);
void menu_button_pressed(sfRenderWindow *window, sfEvent event,
    stock_menu_t *menu);
void draw_score(sfRenderWindow *window, int score);
char *int_to_str(int number);
sfMusic *attack_song(void);
hand_sprite_t *create_animated_hand(const char *path, int frame_count,
    float frame_duration, hand_sprite_t *head);
void draw_hand(sfRenderWindow *window, hand_sprite_t *hand);
void update_hand_frame(sfRenderWindow *window, hand_sprite_t *hand);
int save_score(int score);
#endif
