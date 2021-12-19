/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_bg.c
*/

#include "../include/my.h"

spt *rect_bg_game(sfrw *window, my_game_t game, my_var_t *var)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + var->i;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game.bg_game, rect);
    return (game.bg_game);
}

spt *rect_bg2_game(sfrw *window, my_game_t game, my_var_t *var)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + var->j;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game.bg_game_2, rect);
    return (game.bg_game_2);
}

spt *rect_bg3_game(sfrw *window, my_game_t game, my_var_t *var)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + var->k;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game.bg_game_3, rect);
    return (game.bg_game_3);
}

spt *rect_ronin(sfrw *window, my_game_t game, my_var_t *var)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + var->m;
    rect.width = 64;
    rect.height = 64;
    sfSprite_setTextureRect(game.ronin, rect);
    return (game.ronin);
}

spt *rect2_ronin(sfrw *window, my_game_t game, my_clock_t *c_anim)
{
    sfIntRect rect;
    rect.top = 64;
    rect.left = 0 + c_anim->i;
    rect.width = 64;
    rect.height = 64;
    sfSprite_setTextureRect(game.ronin, rect);
    return (game.ronin);
}