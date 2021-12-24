/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_rect.c
*/

#include "../include/my.h"

void rect_bg_game(sfrw *window, my_game_t *game, my_var_t *var)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + var->i;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game, rect);
}

void rect_bg2_game(sfrw *window, my_game_t *game, my_var_t *var)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + var->j;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_2, rect);
}

void rect_bg3_game(sfrw *window, my_game_t *game, my_var_t *var)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + var->k;
    rect.width = 3840;
    rect.height = 1080;
    sfSprite_setTextureRect(game->bg_game_3, rect);
}

void rect_ronin(sfrw *window, my_game_t *game, my_var_t *var)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + var->m;
    rect.width = 32;
    rect.height = 32;
    sfSprite_setTextureRect(game->ronin, rect);
    return;
}

void rect2_spt(sfrw *window, my_game_t *game, my_clock_t *c_anim)
{
    sfIntRect rect;
    rect.top = 32;
    rect.left = 0 + c_anim->i;
    rect.width = 32;
    rect.height = 32;
    sfSprite_setTextureRect(game->ronin, rect);
}