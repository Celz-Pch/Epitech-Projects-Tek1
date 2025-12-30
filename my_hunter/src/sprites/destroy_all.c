/*
** EPITECH PROJECT, 2025
** destory
** File description:
** destroy
*/

#include "../../include/csfml.h"

void destroy_all(stock_btn_t *btn, stock_decor_t *decor)
{
    destroy_btn(btn);
    destroy_decor(decor);
}
