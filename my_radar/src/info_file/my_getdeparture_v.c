/*
** EPITECH PROJECT, 2025
** my_getvector
** File description:
** departure
*/

#include "../../include/my_radar.h"

int my_vectorlen(sfVector2f *pos)
{
    if (pos->x == -1 || pos->y == -1)
        return -1;
    return (my_intlen(pos->x) + my_intlen(pos->y));
}

sfVector2f my_getdeparture_v(char *file)
{
    sfVector2f departure = {-1, -1};

    while (departure.x == -1 || departure.y == -1) {
        if (departure.x == -1)
            departure.x = my_getnbr(file);
        else
            departure.y = my_getnbr(file + my_intlen(departure.x));
    }
    return departure;
}

sfVector2f my_getarrival_v(char *file, sfVector2f *pos_departure)
{
    sfVector2f arrival = {-1, -1};

    while (arrival.x == -1 || arrival.y == -1) {
        if (arrival.x == -1)
            arrival.x = my_getnbr(file + my_vectorlen(pos_departure));
        else
            arrival.y = my_getnbr(file +
                (my_vectorlen(pos_departure) + my_intlen(arrival.x)) - 1);
    }
    return arrival;
}

sfVector2f my_getspeed_delay(char *file,
    sfVector2f *pos_departure, sfVector2f *pos_arrival)
{
    sfVector2f speed_delay = {-1, -1};

    while (speed_delay.x == -1 || speed_delay.y == -1) {
        if (speed_delay.x == -1) {
            speed_delay.x = my_getnbr(file +
                my_vectorlen(pos_departure) + my_vectorlen(pos_arrival));
        } else {
            speed_delay.y = my_getnbr(file + my_vectorlen(pos_departure)
                + my_vectorlen(pos_arrival) + my_intlen(speed_delay.x));
        }
    }
    return speed_delay;
}
