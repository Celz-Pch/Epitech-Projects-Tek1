/*
** EPITECH PROJECT, 2025
** my
** File description:
** strlen
*/

#include "../../include/my_sudo.h"

int my_strlen_mdp(const char *str, int start)
{
    int i = start;
    int count;

    for (count = 0; str[i] != ':'; i++)
        count++;
    return count;
}

int my_str_uid(const char *str, int start)
{
    int i = start;
    int count;

    for (count = 0; str[i] != '\n'; i++)
        count++;
    return count;
}

int my_strlen(const char *str)
{
    int i = 0;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int my_strlen_salt(const char *str)
{
    int i = 0;
    int count_d = 0;

    for (i = 0; str[i] != '\0' && count_d < 4; i++) {
        if (str[i] == '$')
            count_d++;
    }
    return i;
}
