/*
** EPITECH PROJECT, 2025
** my
** File description:
** getpasswd
*/

#include "../../include/my_sudo.h"

void my_setuid(int uid, try_t *essai)
{
    if (essai->flags_u == 1)
        setuid(uid);
    else
        setuid(0);
}

void my_setgid(int gid, try_t *essai)
{
    if (essai->flags_g == 1 ||
        essai->flags_u == 1)
        setgid(gid);
    else
        setgid(0);
}

char *my_getpasswd(void)
{
    FILE *open = fopen("/etc/passwd", "r");
    char *file;
    struct stat st;
    int tmp = 0;
    int i = 0;

    if (stat("/etc/passwd", &st) == -1)
        return 0;
    file = malloc(st.st_size + 1);
    while (tmp != EOF) {
        tmp = fgetc(open);
        file[i] = (char)tmp;
        i++;
    }
    file[i] = '\0';
    fclose(open);
    return file;
}

int my_getuid(const char *user)
{
    char *file = my_getpasswd();
    int i = my_strstr(file, user) + my_strlen(user);
    char *line = malloc(sizeof(char) * my_str_uid(file, i));
    int stock;

    for (stock = 0; file[i] != '\n'; i++) {
        line[stock] = file[i];
        stock++;
    }
    stock = my_getnbr(line);
    free(line);
    return stock;
}

int my_getgid(const char *user)
{
    char *file = my_getpasswd();
    int i = my_strstr(file, user) + my_strlen(user);
    char *line = malloc(sizeof(char) * my_str_uid(file, i));
    int stock;
    int count_dp = 0;

    for (stock = 0; file[i] != '\n'; i++) {
        if (file[i] == ':')
            count_dp++;
        if (count_dp == 3 && file[i] != ':') {
            line[stock] = file[i];
            stock++;
        }
    }
    stock = my_getnbr(line);
    free(line);
    return stock;
}
