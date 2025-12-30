/*
** EPITECH PROJECT, 2025
** setting_up.h
** File description:
** setting_up.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

#ifndef SETTING_UP
    #define SETTING_UP

typedef struct bsq_s {
    int rows;
    int cols;
    char **map;
    int **dp;
    int max_size;
    int max_i;
    int max_j;
} bsq_t;

char **my_str_to_word_array(char const *str);
int get_row(char **buff_word_array);
int get_col(char **buff_word_array);
int my_strlen(char const *str);
int generation_map(int lengt, char *pattern);
void send_to_setting_up(char *argv);
void main_find(int rows, int cols, char **map);
int setting_up(char *buff, int if_generate);

#endif
