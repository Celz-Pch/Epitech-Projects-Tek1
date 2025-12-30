/*
** EPITECH PROJECT, 2025
** timer
** File description:
** timer on the screen
*/

#include "../../include/my_radar.h"

char *int_to_str(char *buffer, int minutes, int secondes)
{
    buffer[0] = '0' + minutes / 10;
    buffer[1] = '0' + minutes % 10;
    buffer[2] = ' ';
    buffer[3] = ':';
    buffer[4] = ' ';
    buffer[5] = '0' + secondes / 10;
    buffer[6] = '0' + secondes % 10;
    buffer[7] = '\0';
    return buffer;
}

void create_timer(sfRenderWindow *window, sfClock *clock)
{
    sfTime elapsed = sfClock_getElapsedTime(clock);
    int total_seconds = elapsed.microseconds / 1000000;
    int minutes = total_seconds / 60;
    int seconds = total_seconds % 60;
    char timer_str[10];
    sfText *timer_text = sfText_create();
    sfFont *font = sfFont_createFromFile("./assets/Arial.ttf");

    sfText_setFont(timer_text, font);
    sfText_setCharacterSize(timer_text, 30);
    sfText_setFillColor(timer_text, sfWhite);
    sfText_setPosition(timer_text, (sfVector2f){1750, 20});
    int_to_str(timer_str, minutes, seconds);
    sfText_setString(timer_text, timer_str);
    sfRenderWindow_drawText(window, timer_text, NULL);
}
