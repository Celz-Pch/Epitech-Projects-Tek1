/*
** EPITECH PROJECT, 2025
** my_getusername
** File description:
** my_getusername
*/

#include "../../include/my_sudo.h"

int my_strint(int number)
{
    int stock = number;
    int count = 0;

    while (stock > 0) {
        stock = stock / 10;
        count++;
    }
    return count;
}

char *int_to_str(int number)
{
    int len;
    int stock;
    char *res;

    if (number == 0) {
        res = malloc(2);
        res[0] = '0';
        res[1] = '\0';
        return res;
    }
    len = my_strint(number);
    res = malloc(len + 1);
    stock = number;
    for (int i = 0; i < len; i++) {
        res[len - 1 - i] = (stock % 10) + '0';
        stock = stock / 10;
    }
    res[len] = '\0';
    return res;
}

int found_start(char *file, int pos_uid)
{
    int i;

    for (i = pos_uid; file[i] != '\n'; i--);
    return i;
}

int my_userlen(char *file, int pos_start)
{
    int i;
    int count = 0;

    for (int i = pos_start; file[i] != ':'; i++)
        count++;
    return count;
}

char *my_getusername(void)
{
    char *file = my_getpasswd();
    char *to_find = int_to_str(getuid());
    int place = found_start(file, my_strstr(file, to_find));
    char *user = malloc(sizeof(char) * (my_userlen(file, place) + 1));
    int stock = 0;

    for (int i = place + 1; file[i] != ':'; i++) {
        user[stock] = file[i];
        stock++;
    }
    user[stock] = '\0';
    return user;
}
