/*
** EPITECH PROJECT, 2025
** my
** File description:
** getsalt
*/

#include "../../include/my_sudo.h"

char *my_getsalt(const char *password_hash)
{
    char *salt = malloc(sizeof(char) * (my_strlen_salt(password_hash) + 1));
    int count_d = 0;
    int i = 0;

    for (; password_hash[i] != '\0'; i++) {
        salt[i] = password_hash[i];
        if (password_hash[i] == '$')
            count_d++;
        if (count_d == 4)
            break;
    }
    salt[i + 1] = '\0';
    return salt;
}
