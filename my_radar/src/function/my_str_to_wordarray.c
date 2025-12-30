/*
** EPITECH PROJECT, 2025
** my_str_to_wordarray
** File description:
** word array
*/

#include "../../include/my_radar.h"

static int count_lines(const char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '\n')
            count++;
    }
    return count;
}

static char *copy_line(const char *str, int start, int end)
{
    int len = end - start;
    char *word;

    if (str[end + 1] == '\0')
        len++;
    word = malloc(sizeof(char) * (len + 1));
    if (!word)
        return NULL;
    for (int i = 0; i < len; i++)
        word[i] = str[start + i];
    word[len] = '\0';
    return word;
}

char **my_str_to_word_array(const char *str)
{
    int i = 0;
    int start = 0;
    int word_count = count_lines(str);
    char **tab = malloc(sizeof(char *) * (word_count + 2));
    char *line;

    if (!tab)
        return NULL;
    for (int k = 0; str[k]; k++) {
        if (str[k] == '\n' || str[k + 1] == '\0') {
            line = copy_line(str, start, k);
            tab[i] = line;
            i++;
            start = k + 1;
        }
    }
    tab[i] = NULL;
    return tab;
}
