/*
** EPITECH PROJECT, 2025
** my
** File description:
** getsudoers
*/

#include "../../include/my_sudo.h"

char *my_getsudoers(void)
{
    FILE *open = fopen("/etc/sudoers", "r");
    char *file;
    struct stat st;
    int tmp = 0;
    int i = 0;

    if (stat("/etc/sudoers", &st) == -1)
        return 0;
    file = malloc(st.st_size + 1);
    while (tmp != EOF) {
        tmp = fgetc(open);
        file[i] = (char)tmp;
        i++;
    }
    file[i] = '\0';
    fclose(open);
    return file;
}
