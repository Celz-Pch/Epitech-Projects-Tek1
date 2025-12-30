/*
** EPITECH PROJECT, 2025
** my_radar
** File description:
** my_radar
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
#include <sys/stat.h>

#ifndef MY_RADAR
    #define MY_RADAR

typedef struct background {
    sfSprite *sprite;
    sfTexture *texture;
    struct background *next;
} background_t;

typedef struct plane_stock {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos_departure;
    sfVector2f pos_arrival;
    sfRectangleShape *hitbox;
    int delay;
    float speed;
    sfBool active;
    int show_sprite;
    int show_hitbox;
    struct plane_stock *next;
} plane_stock_t;

typedef struct tower_stock {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    float radius;
    int show_sprite;
    struct tower_stock *next;
} tower_stock_t;

typedef struct circle_stock {
    sfCircleShape *circle;
    sfVector2f *pos;
    float radius;
    int show_circle;
    struct circle_stock *next;
} circle_stock_t;

typedef struct game_stock {
    sfRenderWindow *window;
    sfEvent event;
    background_t *background;
    tower_stock_t *tower;
    circle_stock_t *circle;
    plane_stock_t *plane;
} game_stock_t;

typedef struct corner {
    sfIntRect corners;
} corner_t;

void draw_rect(sfRenderWindow *window, corner_t corners[4]);
background_t *created_background(background_t *background);
void draw_background(sfRenderWindow *window, background_t *background);
int my_getnbr(char *str);
char **my_str_to_word_array(const char *str);
int my_intlen(int nb);
int my_strcmp(char *s1, char *s2);
char *my_getinfo(char *file);
char *my_getinfo_t(char *file);
char *my_getinfo_a(char *file);
tower_stock_t *tower_init(char *argv, tower_stock_t **tower);
sfVector2f my_getvector(char *line);
int my_getradius(char *line, sfVector2f *pos);
void draw_tower(sfRenderWindow *window, tower_stock_t *tower);
circle_stock_t *circle_init(char *argv, circle_stock_t **circle);
void draw_circle(sfRenderWindow *window, circle_stock_t *circle);
sfVector2f my_getarrival_v(char *file, sfVector2f *pos_departure);
plane_stock_t *plane_init(char *argv, plane_stock_t **plane);
void draw_plane(sfRenderWindow *window, plane_stock_t *plane);
void move_plane(plane_stock_t **plane);
void draw_hitbox(sfRenderWindow *window, plane_stock_t *hitbox);
void activate_planes(plane_stock_t *plane, sfClock *clock);
void check_plane_around_tower(plane_stock_t *plane, tower_stock_t *tower);
void check_colision_plane(plane_stock_t **plane);
void create_timer(sfRenderWindow *window, sfClock *clock);
float my_get_delay(char *file);
char **my_str_to_word_array_test(const char *str);
int my_strlen(char *file);
void corner_colision(plane_stock_t *plane, corner_t corner[4]);
void open_start_window(sfRenderWindow *window, sfEvent event,
    corner_t corners[4], char *file);
float my_get_speed(char *file);
void destroy_planes(plane_stock_t *plane);
void destroy_towers(tower_stock_t *tower);
void destroy_circles(circle_stock_t *circle);
void destroy_background(background_t *background);
void destroy_game(game_stock_t *game, sfClock *clock);
#endif
