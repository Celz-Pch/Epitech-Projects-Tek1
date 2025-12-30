/*
** EPITECH PROJECT, 2025
** my_exec
** File description:
** my_exec
*/

#include "../../include/my_sudo.h"

int my_exec(char *arg0, char **argv1, try_t *user_get)
{
    if (user_get->groups != NULL && user_get->flags_g == 1) {
        setgid(my_getgid(user_get->groups));
    } else if (user_get->user != NULL && user_get->flags_u == 1) {
        setgid(my_getgid(user_get->user));
        setuid(my_getuid(user_get->user));
    }
    printf("\n");
    if (execvp(arg0, argv1) == -1)
        return 84;
    return 0;
}

int my_exec_root(char *arg0, char **argv1)
{
    if (execvp(arg0, argv1) == -1)
        return 84;
    return 0;
}

int my_exec_root_flags(char *arg2, char **argv3, try_t *user_get)
{
    if (user_get->groups != NULL && user_get->flags_g == 1) {
        setgid(my_getgid(user_get->groups));
    } else if (user_get->user != NULL && user_get->flags_u == 1) {
        setgid(my_getgid(user_get->user));
        setuid(my_getuid(user_get->user));
    }
    if (execvp(arg2, argv3) == -1)
        return 84;
    return 0;
}
