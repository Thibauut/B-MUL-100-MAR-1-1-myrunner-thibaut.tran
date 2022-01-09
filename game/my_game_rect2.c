/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_rect2.c
*/

#include "../include/my.h"

int rect_bg6_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->o;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_6, rect);
    return (0);
}

int rect_bg7_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->p;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_7, rect);
    return (0);
}

int rect_bg8_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->q;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_8, rect);
    return (0);
}

int rect_bg9_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->r;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_9, rect);
    return (0);
}

int rect_bg10_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_bg->s;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_10, rect);
    return (0);
}