/*
** EPITECH PROJECT, 2025
** settingUp
** File description:
** First project Epitech
*/

#include "../include/setting_up.h"
#include "../include/my.h"

static void my_show_word_array(bsq_t *bsq)
{
    int i = 0;

    write(1, bsq->map, get_col(bsq->map) * get_row(bsq->map));
    my_printf("\n");
}

static int min3(int a, int b, int c)
{
    int min = a;

    if (b < min)
        min = b;
    if (c < min)
        min = c;
    return min;
}

static void find_biggest_square(bsq_t *bsq, int i)
{
    for (int j = 0; j < bsq->cols; j++) {
        if (bsq->map[i][j] == 'o') {
            bsq->dp[i][j] = 0;
            continue;
        }
        if (i == 0 || j == 0) {
            bsq->dp[i][j] = 1;
        } else {
            bsq->dp[i][j] = 1 + min3(
                bsq->dp[i - 1][j],
                bsq->dp[i][j - 1],
                bsq->dp[i - 1][j - 1]
            );
        }
        if (bsq->dp[i][j] > bsq->max_size) {
            bsq->max_size = bsq->dp[i][j];
            bsq->max_i = i;
            bsq->max_j = j;
        }
    }
}

static void print_map(bsq_t *bsq)
{
    for (int i = 0; i < bsq->rows; i++) {
        for (int j = 0; j < bsq->cols; j++)
            my_printf("%c", bsq->map[i][j]);
        my_printf("\n");
    }
}

void draw_square(bsq_t *bsq)
{
    for (int i = bsq->max_i; i > bsq->max_i - bsq->max_size; i--)
        for (int j = bsq->max_j; j > bsq->max_j - bsq->max_size; j--)
            bsq->map[i][j] = 'x';
}

void free_dp(bsq_t *bsq)
{
    for (int i = 0; i < bsq->rows; i++)
        free(bsq->dp[i]);
    free(bsq->dp);
}

void main_find(int rows, int cols, char **map)
{
    bsq_t bsq = {
        .rows = rows,
        .cols = cols,
        .map = map,
        .dp = malloc(rows * sizeof(int *)),
        .max_size = 0,
        .max_i = 0,
        .max_j = 0
    };

    if (!bsq.dp)
        return;
    for (int i = 0; i < rows; i++)
        bsq.dp[i] = malloc(cols * sizeof(int));
    for (int i = 0; i < rows; i++)
        find_biggest_square(&bsq, i);
    draw_square(&bsq);
    print_map(&bsq);
    free_dp(&bsq);
}

int setting_up(char *buff, int if_generate)
{
    char **buff_word_array = my_str_to_word_array(buff);

    if (buff_word_array == NULL)
        return 84;
    if (if_generate == 1)
        main_find(get_row(buff_word_array), get_col(buff_word_array)
            , buff_word_array + 1);
    if (if_generate == 0)
        main_find(get_row(buff_word_array), get_col(buff_word_array)
            , buff_word_array);
    return 0;
}

static void verif_error_in_loop(size_t n, int fd, char *buf)
{
    if (n == -1) {
        free(buf);
        close(fd);
    }
}

void send_to_setting_up(char *argv)
{
    int fd = open(argv, O_RDONLY);
    char *buf;
    struct stat st;
    size_t total_read;
    size_t n;

    if (stat(argv, &st) == -1)
        return;
    buf = malloc(st.st_size + 1);
    total_read = 0;
    while (total_read < st.st_size) {
        n = read(fd, buf + total_read, st.st_size - total_read);
        verif_error_in_loop(n, fd, buf);
        if (n == 0)
            break;
        total_read += n;
    }
    buf[total_read] = '\0';
    setting_up(buf, 1);
    free(buf);
}
