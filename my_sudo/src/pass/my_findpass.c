/*
** EPITECH PROJECT, 2025
** my
** File description:
** findpass
*/

#include "../../include/my_sudo.h"

char *find_passwd(char *file)
{
    const char *user = my_getusername();
    int i = my_strstr(file, user);
    int start_hash = my_strlen_mdp(file, i + my_strlen(user) + 1);
    char *hash_real = malloc(sizeof(char) * (start_hash + 1));
    int stock = 0;

    for (i = i + my_strlen(user) + 1; file[i] != ':'; i++) {
        hash_real[stock] = file[i];
        stock++;
    }
    hash_real[stock] = '\0';
    return hash_real;
}
