/*
** EPITECH PROJECT, 2025
** genaration map
** File description:
** map generations
*/

#include "../include/setting_up.h"
#include "../include/my.h"

void free_word_array(int line, char **result)
{
    for (int j = 0; j < line; j++)
        free(result[j]);
}

int reset_j(int len, int j)
{
    if (j == len) {
        j = 0;
        return j;
    }
    return j;
}

char *my_put_str_len(char *str, int len, int len_max)
{
    char *result = malloc(sizeof(char) * ((len_max + 1) * (len_max + 1) + 1));
    int j = 0;
    int pos = 0;

    for (int line = 0; line <= len_max; line++) {
        for (int i = 0; i < len_max; i++) {
            j = reset_j(len, j);
            result[pos] = str[j];
            pos++;
            j++;
        }
        result[pos] = '\n';
        pos++;
    }
    return result;
}

int verif_pattern(char *pattern)
{
    int i = 0;

    for (i = 0; pattern[i] != '\0'; i++) {
        if (pattern[i] != '.' && pattern[i] != 'o')
            return 1;
    }
    if (i == 0)
        return 1;
    return 0;
}

int generation_map(int lengt, char *pattern)
{
    int i = 0;
    char **buff;

    if (verif_pattern(pattern) == 1)
        return 84;
    else
        setting_up(my_put_str_len(pattern, my_strlen(pattern), lengt), 0);
    return 0;
}
