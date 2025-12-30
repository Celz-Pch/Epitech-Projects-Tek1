/*
** EPITECH PROJECT, 2025
** echo
** File description:
** echo
*/

#include "../../include/my_sudo.h"

void disable_raw_mode(struct termios *old_tio)
{
    tcsetattr(STDIN_FILENO, TCSANOW, old_tio);
}

int enable_raw_mode(struct termios *old_tio)
{
    struct termios new_tio;

    if (!isatty(STDIN_FILENO))
        return -1;
    if (tcgetattr(STDIN_FILENO, old_tio) == -1)
        return -1;
    new_tio = *old_tio;
    new_tio.c_lflag &= ~(ICANON | ECHO);
    new_tio.c_cc[VMIN] = 1;
    new_tio.c_cc[VTIME] = 0;
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_tio) == -1)
        return -1;
    return 0;
}
