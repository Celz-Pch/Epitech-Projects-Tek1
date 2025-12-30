/*
** EPITECH PROJECT, 2025
** update
** File description:
** anim
*/

#include "../../include/csfml.h"

void update_positions(animated_sprite_t *anim_list, float delta_time)
{
    const float speed = 950.0f;

    for (animated_sprite_t *tmp = anim_list; tmp != NULL; tmp = tmp->next) {
        tmp->position.x += speed * delta_time;
        sfSprite_setPosition(tmp->sprite, tmp->position);
    }
}

void update_animation(animated_sprite_t *anim)
{
    sfTime elapsed = sfClock_getElapsedTime(anim->anim_clock);
    float seconds = sfTime_asSeconds(elapsed);
    sfIntRect rect;

    if (seconds >= anim->frame_duration) {
        anim->current_frame = (anim->current_frame + 1) % anim->frame_count;
        rect = (sfIntRect){anim->current_frame * anim->frame_width,
            0, anim->frame_width, anim->frame_height};
        sfSprite_setTextureRect(anim->sprite, rect);
        sfClock_restart(anim->anim_clock);
    }
}

void update_animations(animated_sprite_t *list)
{
    for (animated_sprite_t *tmp = list; tmp != NULL; tmp = tmp->next) {
        update_animation(tmp);
    }
}
