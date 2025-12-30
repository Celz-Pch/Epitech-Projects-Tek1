/*
** EPITECH PROJECT, 2025
** get
** File description:
** count
*/

#include "../include/setting_up.h"
#include "../include/my.h"

int my_strlen(char const *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}

int get_row(char **buff_word_array)
{
    int row = 0;

    while (buff_word_array[row + 1] != NULL)
        row++;
    return row;
}

int get_col(char **buff_word_array)
{
    if (buff_word_array[1] == NULL)
        return 0;
    return my_strlen(buff_word_array[1]);
}
