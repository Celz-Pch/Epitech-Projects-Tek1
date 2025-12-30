/*
** EPITECH PROJECT, 2025
** colision
** File description:
** corner
*/

#include "../../include/my_radar.h"

static sfBool check_hitbox_collision(sfRectangleShape *hitbox1,
    sfRectangleShape *hitbox2)
{
    sfVector2f pos1 = sfRectangleShape_getPosition(hitbox1);
    sfVector2f pos2 = sfRectangleShape_getPosition(hitbox2);
    sfVector2f size1 = sfRectangleShape_getSize(hitbox1);
    sfVector2f size2 = sfRectangleShape_getSize(hitbox2);

    if (pos1.x < pos2.x + size2.x && pos1.x + size1.x > pos2.x &&
        pos1.y < pos2.y + size2.y && pos1.y + size1.y > pos2.y)
        return sfTrue;
    return sfFalse;
}

static sfBool is_plane_in_tower_zone(sfRectangleShape *hitbox)
{
    sfColor color = sfRectangleShape_getFillColor(hitbox);

    if (color.r == 255 && color.g == 0 && color.b == 0)
        return sfTrue;
    return sfFalse;
}

static void destroy_plane(plane_stock_t *plane)
{
    sfSprite_destroy(plane->sprite);
    sfTexture_destroy(plane->texture);
    sfRectangleShape_destroy(plane->hitbox);
    free(plane);
}

static void delete_plane(plane_stock_t **head, plane_stock_t *to_delete)
{
    plane_stock_t *current = *head;
    plane_stock_t *prev = NULL;

    if (*head == to_delete) {
        *head = (*head)->next;
        destroy_plane(to_delete);
        return;
    }
    while (current != NULL && current != to_delete) {
        prev = current;
        current = current->next;
    }
    if (current != NULL) {
        prev->next = current->next;
        destroy_plane(current);
    }
}

static sfBool check_one_collision(plane_stock_t **plane, plane_stock_t *current)
{
    plane_stock_t *other = current->next;

    while (other != NULL) {
        if (other->active == sfTrue &&
            !is_plane_in_tower_zone(other->hitbox) &&
            check_hitbox_collision(current->hitbox, other->hitbox)) {
            delete_plane(plane, other);
            delete_plane(plane, current);
            return sfTrue;
        }
        other = other->next;
    }
    return sfFalse;
}

void second_check(plane_stock_t **plane, plane_stock_t *current,
    int *collision_found)
{
    while (current != NULL) {
        if (current->active == sfFalse ||
            is_plane_in_tower_zone(current->hitbox)) {
            current = current->next;
            continue;
        }
        if (check_one_collision(plane, current)) {
            *collision_found = 1;
            break;
        }
        current = current->next;
    }
}

void check_colision_plane(plane_stock_t **plane)
{
    plane_stock_t *current;
    int collision_found = 1;

    while (collision_found) {
        collision_found = 0;
        current = *plane;
        if (current != NULL)
            second_check(plane, current, &collision_found);
    }
}
