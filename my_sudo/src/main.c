/*
** EPITECH PROJECT, 2025
** my_sudo
** File description:
** bootstrap
*/

#include "../include/my_sudo.h"

try_t check_flags(try_t *flags, char **argv)
{
    int i = 0;

    for (; argv[i] != 0; i++) {
        if (my_strcmp(argv[i], "-u") == 0) {
            flags->flags_u = 1;
            flags->user = argv[i + 1];
            break;
        }
        if (my_strcmp(argv[i], "-g") == 0) {
            flags->flags_g = 1;
            flags->groups = argv[i + 1];
            break;
        }
    }
    return *flags;
}

int main(int argc, char **argv, char **env)
{
    try_t *essai = malloc(sizeof(try_t));

    essai->try = 0;
    *essai = check_flags(essai, argv);
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0) {
        print_help();
        print_flags();
        return 0;
    }
    if (check_error(argc, argv) == 1)
        return 84;
    if (getuid() == 0 && essai->flags_u == 1)
        my_exec_root_flags(argv[3], &argv[3], essai);
    else if (getuid() == 0)
        my_exec_root(argv[1], &argv[1]);
    if (check_password(essai) == 1)
        my_exec(argv[1], &argv[1], essai);
    else
        return 84;
}
