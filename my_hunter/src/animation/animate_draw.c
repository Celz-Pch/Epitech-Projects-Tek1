/*
** EPITECH PROJECT, 2025
** draw
** File description:
** animate
*/

#include "../../include/csfml.h"

void set_texture_position(animated_sprite_t *anim, int random_y)
{
    sfSprite_setTexture(anim->sprite, anim->texture, sfTrue);
    sfSprite_setPosition(anim->sprite, (sfVector2f){0, random_y});
}

animated_sprite_t *create_animated_sprite(const char *path, int frame_count,
    float frame_duration, animated_sprite_t *head)
{
    animated_sprite_t *anim = malloc(sizeof(animated_sprite_t));
    sfVector2u texture_size;
    sfIntRect rect;
    int random_y = rand() % 800;

    anim->texture = sfTexture_createFromFile(path, NULL);
    anim->sprite = sfSprite_create();
    set_texture_position(anim, random_y);
    anim->position = (sfVector2f){0, random_y};
    anim->anim_clock = sfClock_create();
    anim->current_frame = 0;
    anim->frame_count = frame_count;
    anim->frame_duration = frame_duration;
    texture_size = sfTexture_getSize(anim->texture);
    anim->frame_width = texture_size.x / frame_count;
    anim->frame_height = texture_size.y;
    rect = (sfIntRect){0, 0, anim->frame_width, anim->frame_height};
    sfSprite_setTextureRect(anim->sprite, rect);
    anim->next = head;
    return anim;
}

void draw_animation(sfRenderWindow *window, animated_sprite_t *anim)
{
    for (animated_sprite_t *tmp = anim; tmp != NULL; tmp = tmp->next) {
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
    }
}

void destroy_animation(animated_sprite_t *anim)
{
    if (anim) {
        sfSprite_destroy(anim->sprite);
        sfTexture_destroy(anim->texture);
        sfClock_destroy(anim->anim_clock);
        free(anim);
    }
}
