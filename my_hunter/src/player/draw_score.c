/*
** EPITECH PROJECT, 2025
** draw_socre
** File description:
** draw_score
*/

#include "../../include/csfml.h"

void set_score(sfText *text, sfFont *font, char *str)
{
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, 40);
    sfText_setString(text, str);
    sfText_setFillColor(text, sfWhite);
}

void draw_score(sfRenderWindow *window, int score)
{
    sfFont *font;
    sfText *text;
    char *str;
    sfFloatRect bounds;
    sfVector2u size;
    sfVector2f pos;

    font = sfFont_createFromFile("./assets/arial.otf");
    text = sfText_create();
    str = int_to_str(score);
    set_score(text, font, str);
    bounds = sfText_getLocalBounds(text);
    size = sfRenderWindow_getSize(window);
    pos.x = size.x - bounds.width - 20;
    pos.y = 10;
    sfText_setPosition(text, pos);
    sfRenderWindow_drawText(window, text, NULL);
    free(str);
    sfText_destroy(text);
    sfFont_destroy(font);
}
