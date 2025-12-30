/*
** EPITECH PROJECT, 2025
** my_get
** File description:
** vector2
*/

#include "../../include/my_radar.h"

int my_getnbr(char *str)
{
    int i = 0;
    int letter_dettect = 0;
    int number = 0;
    int negatif = 1;
    int nbr_get = 0;

    while (str[i] != '\0' && letter_dettect == 0) {
        if (str[i] == 45) {
            negatif = negatif * (-1);
        }
        if (str[i] >= 48 && str[i] <= 57) {
            number = number * 10 + (str[i] - 48);
            nbr_get = 1;
        }
        i++;
        if (str[i] < 48 && nbr_get == 1 || str[i] > 57 && nbr_get == 1) {
            letter_dettect = 1;
        }
    }
    return (number * negatif);
}

int my_intlen(int nbm)
{
    int stock = nbm;
    int count = 0;

    while (stock > 0) {
        stock = stock / 10;
        count++;
    }
    return count + 2;
}

sfVector2f my_getvector(char *line)
{
    sfVector2f stock = {-1, -1};
    int i;

    while (stock.x == -1 || stock.y == -1) {
        if (stock.x == -1)
            stock.x = my_getnbr(line);
        else
            stock.y = my_getnbr(line + my_intlen(stock.x));
    }
    return stock;
}
