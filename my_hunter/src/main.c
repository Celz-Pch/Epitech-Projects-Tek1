/*
** EPITECH PROJECT, 2025
** main function
** File description:
** main fucntion
*/

#include "../include/csfml.h"

void check_h(int argc, char **argv)
{
    if (argc >= 2 && argv[1][0] == '-'
        && argv[1][1] == 'h' && argv[1][2] == '\0') {
        write(1, "USAGE\n", 6);
        write(1, "    ./my_hunter\n", 16);
        write(1, "DESCRIPTION\n", 12);
        write(1, "    Simple hunter game using CSFML\n", 36);
        write(1, "    You have to shoot the duck\n", 33);
        write(1, "    You have 3 lives\n", 22);
        write(1, "    You have to click on the duck to kill it\n", 47);
        write(1, "    You can press escape to quit the game\n", 43);
        write(1, "    You can press enter to restart the game at the end\n",
            56);
    }
}

int init_game(sfRenderWindow **window, stock_decor_t **decor, stock_btn_t **btn)
{
    sfVideoMode mode = {1920, 1080, 32};

    *window = sfRenderWindow_create(mode, "My Hunter",
        sfResize | sfClose, NULL);
    if (!(*window))
        return 84;
    sfRenderWindow_setFramerateLimit(*window, 60);
    *btn = add_btn(*btn, "./assets/play_btn.png",
        &(sfVector2f){0.25, 0.22}, &(sfVector2f){736.3f, 490});
    *decor = add_decor(*decor, "./assets/background.png",
        &(sfVector2f){0.286, 0.39}, &(sfVector2f){0.0f, 0.0f});
    return 0;
}

void cleanup_game(sfRenderWindow *window,
    stock_decor_t *decor, stock_btn_t *btn)
{
    destroy_all(btn, decor);
    sfRenderWindow_destroy(window);
}

int main(int argc, char **argv)
{
    sfRenderWindow *window;
    sfEvent event;
    stock_decor_t *decor = NULL;
    stock_btn_t *btn = NULL;
    int status;

    check_h(argc, argv);
    if (argc >= 2 && argv[1][0] == '-'
        && argv[1][1] == 'h' && argv[1][2] == '\0')
        return 0;
    srand(time(NULL));
    status = init_game(&window, &decor, &btn);
    if (status != 0)
        return status;
    open_default_windows(window, event, decor, btn);
    cleanup_game(window, decor, btn);
    return 0;
}
