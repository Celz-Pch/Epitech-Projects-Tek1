/*
** EPITECH PROJECT, 2025
** kill
** File description:
** anim
*/

#include "../../include/csfml.h"

void free_anim(animated_sprite_t *tmp)
{
    if (tmp->texture)
        sfTexture_destroy(tmp->texture);
    if (tmp->sprite)
        sfSprite_destroy(tmp->sprite);
    free(tmp);
}

void remove_anim(animated_sprite_t **anim, animated_sprite_t *tmp,
    animated_sprite_t *prev)
{
    if (prev)
        prev->next = tmp->next;
    else
        *anim = tmp->next;
    free_anim(tmp);
}

void check_kill_anim(sfRenderWindow *window, sfEvent event,
    animated_sprite_t **anim, game_state2_t *state)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    animated_sprite_t *tmp = *anim;
    animated_sprite_t *prev = NULL;
    animated_sprite_t *next;
    sfFloatRect bounds;

    if (event.type != sfEvtMouseButtonPressed)
        return;
    while (tmp) {
        bounds = sfSprite_getGlobalBounds(tmp->sprite);
        if (sfFloatRect_contains(&bounds, mouse.x, mouse.y)) {
            next = tmp->next;
            remove_anim(anim, tmp, prev);
            tmp = next;
            state->score = state->score + 4;
        } else {
            prev = tmp;
            tmp = tmp->next;
        }
    }
}
