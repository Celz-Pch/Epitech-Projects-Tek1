/*
** EPITECH PROJECT, 2025
** my_getinfo_t
** File description:
** my_getinfo_t
*/

#include "../../include/my_radar.h"

char *my_getinfo(char *file)
{
    struct stat st;
    int map = open(file, O_RDONLY, 0777);
    char *buffer;
    int bytes;

    if (stat(file, &st) == -1)
        return NULL;
    buffer = malloc(sizeof(char) * (st.st_size + 1));
    bytes = read(map, buffer, st.st_size);
    buffer[st.st_size] = '\0';
    close(map);
    return buffer;
}

int my_get_start_t(char *file)
{
    int count = 0;
    int count_t = 0;
    int i = 0;

    for (i = 0; file[i] != '\0'; i++) {
        if (file[i] == 'T')
            return i;
    }
    return 0;
}

int my_get_len_t(char *file)
{
    int count = 0;
    int count_t = 0;
    int i = 0;

    for (i = 0; file[i] != '\0'; i++) {
        if (file[i] == 'T')
            count_t = 1;
        if (count_t == 1)
            count++;
    }
    return count;
}

char *my_getinfo_t(char *file)
{
    int place = my_get_start_t(file);
    int count_t = my_get_len_t(file);
    char *stock_t = malloc(sizeof(char *) * (count_t + 1));
    int i = 0;

    for (; file[place] != '\0'; place++) {
        stock_t[i] = file[place];
        i++;
    }
    stock_t[i] = '\0';
    return stock_t;
}
