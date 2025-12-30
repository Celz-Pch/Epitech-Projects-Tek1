/*
** EPITECH PROJECT, 2025
** enemy
** File description:
** enemy
*/

#include "../../include/csfml.h"

void add_enemy_velocity(stock_enemy_t *new, sfVector2f *pos)
{
    new->position = sfSprite_getPosition(new->sprite);
    if (pos->x < 0) {
        new->velocity_x = 8.0f + (rand() % 4);
        new->direction = -1;
    } else {
        new->velocity_x = -(8.0f + (rand() % 4));
        new->direction = 1;
    }
    new->velocity_y = -15.0f - (rand() % 5);
}

stock_enemy_t *add_enemy(stock_enemy_t *head, const char *path,
    sfVector2f *scale, sfVector2f *pos)
{
    stock_enemy_t *new = malloc(sizeof(stock_enemy_t));

    new->image = sfImage_createFromFile("./assets/cible.png");
    if (!new)
        return head;
    new->texture = sfTexture_createFromFile(path, NULL);
    if (!new->texture) {
        free(new);
        return head;
    }
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setScale(new->sprite, *scale);
    sfSprite_setPosition(new->sprite, *pos);
    add_enemy_velocity(new, pos);
    new->clock = sfClock_create();
    new->change_delay = 0.5f;
    new->next = head;
    return new;
}

stock_enemy_t *init_enemy(int count, stock_enemy_t *enemy)
{
    int choix;
    int random_x;

    for (int i = 0; i < count; i++) {
        choix = rand() % 2;
        random_x = (choix == 0) ? -200 : 1850;
        enemy = add_enemy(enemy, "./assets/cible.png",
            &(sfVector2f){0.25, 0.25},
            &(sfVector2f){random_x, 850});
    }
    return enemy;
}

void update_enemy_position(stock_enemy_t *head, float delta_time)
{
    const float GRAVITY = 0.28f;
    const float SPEED_MULTIPLIER = 40.0f;
    stock_enemy_t *tmp = head;
    float angle;
    float adjusted_delta = delta_time * SPEED_MULTIPLIER;

    while (tmp) {
        tmp->velocity_y += GRAVITY * adjusted_delta;
        tmp->position.x += tmp->velocity_x * adjusted_delta;
        tmp->position.y += tmp->velocity_y * adjusted_delta;
        sfSprite_setPosition(tmp->sprite, tmp->position);
        angle = atan2(tmp->velocity_y, tmp->velocity_x) * 180.0f / 3.14159f;
        sfSprite_setRotation(tmp->sprite, angle);
        tmp = tmp->next;
    }
}

static void remove_enemy(stock_enemy_t **head, stock_enemy_t **tmp,
    stock_enemy_t **prev)
{
    stock_enemy_t *to_delete = *tmp;

    if (*prev == NULL) {
        *head = (*tmp)->next;
        *tmp = *head;
    } else {
        (*prev)->next = (*tmp)->next;
        *tmp = (*tmp)->next;
    }
    if (to_delete->texture)
        sfTexture_destroy(to_delete->texture);
    if (to_delete->sprite)
        sfSprite_destroy(to_delete->sprite);
    free(to_delete);
}

stock_enemy_t *remove_offscreen_enemies(stock_enemy_t *head,
    game_state2_t *state)
{
    stock_enemy_t *tmp = head;
    stock_enemy_t *prev = NULL;

    while (tmp) {
        if (tmp->position.y > 1100 ||
            tmp->position.x < -300 ||
            tmp->position.x > 2200) {
            remove_enemy(&head, &tmp, &prev);
            state->life = state->life - 1;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
    return head;
}
