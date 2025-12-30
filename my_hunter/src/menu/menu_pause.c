/*
** EPITECH PROJECT, 2025
** check_life
** File description:
** check_life
*/

#include "../../include/csfml.h"

stock_menu_t *menu_pause(sfRenderWindow *window, sfEvent event,
    stock_menu_t *menu)
{
    if (menu && my_strcmp(menu->name, "resume") == 0) {
        return NULL;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
        if (menu) {
            destroy_menu(menu);
            return NULL;
        }
        menu = add_menu(menu, "./assets/resume.png",
            &(sfVector2f){0.25, 0.25}, &(sfVector2f){812.3f, 430});
        menu = add_menu(menu, "./assets/setting.png",
            &(sfVector2f){0.25, 0.2}, &(sfVector2f){812.3f, 530});
        menu = add_menu(menu, "./assets/quit.png",
            &(sfVector2f){0.25, 0.2}, &(sfVector2f){812.3f, 630});
        menu = add_menu(menu, "./assets/menupause.png",
            &(sfVector2f){1.2, 1.2}, &(sfVector2f){728.3f, 220});
    }
    return menu;
}
