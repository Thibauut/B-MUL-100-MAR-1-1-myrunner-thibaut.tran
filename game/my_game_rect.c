/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_rect.c
*/

#include "../include/my.h"

int rect_bg_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->i;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_1, rect);
    return (0);
}

int rect_bg2_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->j;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_2, rect);
    return (0);
}

int rect_bg3_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->k;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_3, rect);
    return (0);
}

int rect_bg4_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->l;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_4, rect);
    return (0);
}

int rect_bg5_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->n;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_5, rect);
    return (0);
}