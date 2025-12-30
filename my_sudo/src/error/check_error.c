/*
** EPITECH PROJECT, 2025
** check
** File description:
** error
*/

#include "../../include/my_sudo.h"

void print_help(void)
{
    printf("usage: ./my_sudo -h\n");
    printf("usage: ./my_sudo [-ug] [command [args ...]]\n");
}

void print_flags(void)
{
    printf("\nFlags:\n\n");
    printf("-h.\n");
    printf("    Display a short help message to the standard output and "
        "exit.\n\n");
    printf("-u user,\n");
    printf("    Run the command as a user other than the default target "
        "user (usually root)\n\n");
    printf("-g group,\n");
    printf("    Run the command with the primary group set to group "
        "instead of the primary group specified by the target\n");
    printf("    user's password database entry\n");
}

int check_sudoers(void)
{
    char *sudoers = my_getsudoers();

    if (!strstr(sudoers, my_getusername())) {
        return 1;
    }
    return 0;
}

int check_error(int argc, char **argv)
{
    if (argc == 1) {
        print_help();
        print_flags();
        return 1;
    }
    if (check_sudoers() == 1) {
        printf("\n");
        printf("%s is not in the my_sudoers file.\n", my_getusername());
        return 84;
    }
    return 0;
}
