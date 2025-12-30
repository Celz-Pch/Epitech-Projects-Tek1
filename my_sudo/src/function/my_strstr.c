/*
** EPITECH PROJECT, 2025
** str
** File description:
** my_strstr
*/

int my_strstr(const char *str, const char *to_f)
{
    int i = 0;
    int k = 0;

    if (*to_f == '\0')
        return -1;
    while (str[i] != '\0') {
        k = 0;
        while (str[i + k] != '\0' && to_f[k] != '\0' && str[i + k] == to_f[k]) {
            k++;
        }
        if (to_f[k] == '\0')
            return i;
        i++;
    }
    return 0;
}
