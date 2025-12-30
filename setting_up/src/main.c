/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include "../include/setting_up.h"
#include "../include/my.h"

int main(int argc, char **argv)
{
    if (argc == 2)
        send_to_setting_up(argv[1]);
    if (argc == 3)
        generation_map(my_getnbr(argv[1]), argv[2]);
}
