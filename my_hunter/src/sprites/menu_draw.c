/*
** EPITECH PROJECT, 2025
** draw_decor
** File description:
** draw_decor
*/

#include "../../include/csfml.h"

void check_name_action(sfRenderWindow *window, sfEvent event,
    stock_menu_t *menu, sfFloatRect *bounds)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);

    if (sfFloatRect_contains(bounds, mouse.x, mouse.y)) {
        if (my_strcmp(menu->name, "resume") == 0) {
            menu_pause(window, event, menu);
        }
        if (my_strcmp(menu->name, "setting") == 0) {
            return;
        }
        if (my_strcmp(menu->name, "quit") == 0) {
            sfRenderWindow_close(window);
        }
    }
}

void menu_button_pressed(sfRenderWindow *window, sfEvent event,
    stock_menu_t *menu)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfFloatRect bounds;

    if (menu == NULL)
        return;
    if (event.type == sfEvtMouseButtonPressed) {
        for (stock_menu_t *tmp = menu; tmp != NULL; tmp = tmp->next) {
            bounds = sfSprite_getGlobalBounds(tmp->sprite);
            check_name_action(window, event, tmp, &bounds);
        }
    }
}

stock_menu_t *add_menu(stock_menu_t *head, const char *path,
    sfVector2f *scale, sfVector2f *pos)
{
    stock_menu_t *new = malloc(sizeof(stock_menu_t));

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
    new->position = sfSprite_getPosition(new->sprite);
    new->name = getname(path);
    new->next = head;
    return new;
}

void destroy_menu(stock_menu_t *head)
{
    stock_menu_t *tmp;

    while (head) {
        tmp = head->next;
        if (head->texture)
            sfTexture_destroy(head->texture);
        if (head->sprite)
            sfSprite_destroy(head->sprite);
        free(head);
        head = tmp;
    }
}

void draw_menu(sfRenderWindow *window, stock_menu_t *head)
{
    for (stock_menu_t *tmp = head; tmp != NULL; tmp = tmp->next)
        sfRenderWindow_drawSprite(window, tmp->sprite, NULL);
}
