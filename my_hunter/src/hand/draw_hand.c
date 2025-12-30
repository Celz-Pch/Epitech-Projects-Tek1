/*
** EPITECH PROJECT, 2025
** draw_hand
** File description:
** draw
*/

#include "../../include/csfml.h"

static void update_hand_current(sfRenderWindow *window,
    hand_sprite_t *hand, float ratio)
{
    int visible_frames;
    int new_frame;
    sfIntRect rect;

    visible_frames = (hand->frame_count > 4) ? 4 : hand->frame_count;
    new_frame = (int)(ratio * (visible_frames - 1));
    if (new_frame != hand->current_frame) {
        hand->current_frame = new_frame;
        sfRenderWindow_clear(window, sfBlack);
        rect.left = hand->frame_width * hand->current_frame;
        rect.top = 0;
        rect.width = hand->frame_width;
        rect.height = hand->frame_height;
        sfSprite_setTextureRect(hand->sprite, rect);
    }
}

void update_hand_frame(sfRenderWindow *window, hand_sprite_t *hand)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2u win_size = sfRenderWindow_getSize(window);
    float ratio = (float)mouse.x / (float)win_size.x;
    int visible_frames;
    int new_frame;
    sfIntRect rect;

    if (!hand)
        return;
    if (ratio < 0)
        ratio = 0;
    if (ratio > 1)
        ratio = 1;
    ratio *= 1.5f;
    if (ratio > 1)
        ratio = 1;
    update_hand_current(window, hand, ratio);
}

void set_texture_position_hand(hand_sprite_t *hand)
{
    sfSprite_setTexture(hand->sprite, hand->texture, sfTrue);
    sfSprite_setPosition(hand->sprite, (sfVector2f){800, 593});
    sfSprite_setScale(hand->sprite, (sfVector2f){2.5, 2.5});
}

hand_sprite_t *create_animated_hand(const char *path, int frame_count,
    float frame_duration, hand_sprite_t *head)
{
    hand_sprite_t *hand = malloc(sizeof(hand_sprite_t));
    sfVector2u texture_size;
    sfIntRect rect;

    hand->texture = sfTexture_createFromFile(path, NULL);
    hand->sprite = sfSprite_create();
    set_texture_position_hand(hand);
    hand->position = (sfVector2f){800, 593};
    hand->hand_clock = sfClock_create();
    hand->current_frame = 0;
    hand->frame_count = frame_count;
    hand->frame_duration = frame_duration;
    texture_size = sfTexture_getSize(hand->texture);
    hand->frame_width = texture_size.x / frame_count;
    hand->frame_height = texture_size.y;
    rect = (sfIntRect){0, 0, hand->frame_width, hand->frame_height};
    sfSprite_setTextureRect(hand->sprite, rect);
    hand->next = head;
    return hand;
}

void draw_hand(sfRenderWindow *window, hand_sprite_t *hand)
{
    for (hand_sprite_t *tmp = hand; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}

void destroy_hand(hand_sprite_t *hand)
{
    if (hand) {
        sfSprite_destroy(hand->sprite);
        sfTexture_destroy(hand->texture);
        sfClock_destroy(hand->hand_clock);
        free(hand);
    }
}
