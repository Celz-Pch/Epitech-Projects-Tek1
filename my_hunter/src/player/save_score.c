/*
** EPITECH PROJECT, 2025
** save
** File description:
** score
*/

#include "../../include/csfml.h"

int my_strintlen(int number)
{
    int stock = number;
    int count = 0;

    while (stock > 0) {
        stock = stock / 10;
        count++;
    }
    return count;
}

int count_digits(int n)
{
    int c = 0;

    if (n == 0)
        return 1;
    while (n > 0) {
        n /= 10;
        c++;
    }
    return c;
}

int reverse_fill(int n, char *tmp)
{
    int d = 0;

    while (n > 0) {
        tmp[d] = '0' + (n % 10);
        n /= 10;
        d++;
    }
    return d;
}

int comp(int n, char *buf)
{
    char tmp[20];
    int neg = 0;
    int d;
    int i = 0;

    if (n < 0) {
        buf[i] = '-';
        i++;
        n = -n;
        neg = 1;
    }
    d = reverse_fill(n, tmp);
    while (d > 0) {
        d--;
        buf[i] = tmp[d];
        i++;
    }
    buf[i] = '\0';
    return i;
}

int save_score(int score)
{
    int fd;
    char buffer[32];
    int len;

    fd = open("score.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1)
        return -1;
    len = comp(score, buffer);
    write(fd, "Score: ", 7);
    write(fd, buffer, len);
    write(fd, "\n", 1);
    close(fd);
    return 0;
}
