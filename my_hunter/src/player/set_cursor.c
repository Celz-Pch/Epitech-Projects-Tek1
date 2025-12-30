/*
** EPITECH PROJECT, 2025
** check_life
** File description:
** check_life
*/

#include "../../include/csfml.h"

void set_cursor(sfRenderWindow *window)
{
    sfImage *img = sfImage_createFromFile("./assets/cursor.png");
    sfCursor *cursor;
    const sfUint8 *pixels = sfImage_getPixelsPtr(img);
    sfVector2u size;
    sfVector2u hotspot;

    if (img) {
        size = sfImage_getSize(img);
        hotspot = (sfVector2u) {25, 25};
        cursor = sfCursor_createFromPixels(pixels, size, hotspot);
        if (cursor)
            sfRenderWindow_setMouseCursor(window, cursor);
        sfImage_destroy(img);
    }
}
