/*
** EPITECH PROJECT, 2025
** draw_decor
** File description:
** draw_decor
*/

#include "../../include/csfml.h"

int my_strlen(const char *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);
    return i;
}

int skip_assets(const char *name)
{
    int i = 0;
    int slash_count = 0;

    while (name[i] != '\0') {
        if (name[i] == '/')
            slash_count++;
        if (slash_count == 2) {
            i++;
            break;
        }
        i++;
    }
    return i;
}

char *getname(const char *name)
{
    int start = skip_assets(name);
    int i = start;
    int len;
    char *result;

    while (name[i] != '\0' && name[i] != '.')
        i++;
    len = i - start;
    result = malloc(len + 1);
    if (!result)
        return NULL;
    for (int j = 0; j < len; j++)
        result[j] = name[start + j];
    result[len] = '\0';
    return result;
}
