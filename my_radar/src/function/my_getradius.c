/*
** EPITECH PROJECT, 2025
** my_getradius
** File description:
** radius
*/

#include "../../include/my_radar.h"

int my_getvector_len(sfVector2f *pos)
{
    int pos1 = pos->x;
    int pos2 = pos->y;
    int len_pos;

    len_pos = my_intlen(pos1) + my_intlen(pos2);
    return len_pos;
}

int my_getradius(char *line, sfVector2f *pos)
{
    int len_pos = my_getvector_len(pos);

    return my_getnbr(line + len_pos);
}
