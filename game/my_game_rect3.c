/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_rect3.c
*/

#include "../include/my.h"

int rect_bg11_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->y;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_11, rect);
    return (0);
}