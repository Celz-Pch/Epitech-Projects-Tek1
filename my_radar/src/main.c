/*
** EPITECH PROJECT, 2025
** main.c
** File description:
** main.c
*/

#include "../include/my_radar.h"

static int print_usage(void)
{
    write(1, "Air traffic simulation panel\n", 30);
    write(1, "USAGE\n", 6);
    write(1, "  ./my_radar [OPTIONS] path_to_script\n", 39);
    write(1, "  path_to_script The path to the script file.\n", 47);
    write(1, "OPTIONS\n", 8);
    write(1, "  -h print the usage and quit.\n", 32);
    write(1, "USER INTERACTIONS\n", 18);
    write(1, "  'L' key enable/disable hitboxes and areas.\n", 46);
    write(1, "  'S' key enable/disable sprites.\n", 34);
    return 0;
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {1920, 1080, 32};
    sfRenderWindow *window = sfRenderWindow_create(mode, "My Radar",
        sfResize | sfClose, NULL);
    sfEvent event;
    corner_t corner[4] = {
        {{0, 0, 960, 540}},
        {{960, 0, 960, 540}},
        {{0, 540, 960, 540}},
        {{960, 540, 960, 540}}
    };

    sfRenderWindow_setFramerateLimit(window, 120);
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return print_usage();
    if (argc != 2) {
        write(2, "my_radar: bad arguments\nretry with -h\n", 38);
        return 84;
    }
    open_start_window(window, event, corner, argv[1]);
    return 0;
}
