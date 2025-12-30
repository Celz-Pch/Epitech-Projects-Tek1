/*
** EPITECH PROJECT, 2025
** close_windows
** File description:
** close_windosw
*/

#include "../../include/csfml.h"

void close_windows(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
}
