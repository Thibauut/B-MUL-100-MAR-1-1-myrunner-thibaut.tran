/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_rect2.c
*/

#include "../../include/my.h"

int rect_spt(sfrw *window, my_game_t *game, my_clock_t *c_run)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_run->i;
    rect.width = 32;
    rect.height = 32;
    sfSprite_setTextureRect(game->p, rect);
    return (0);
}

int rect2_spt(sfrw *window, my_game_t *game, my_clock_t *c_anim)
{
    sfIntRect rect;
    rect.top = 32;
    rect.left = 0 + c_anim->i;
    rect.width = 32;
    rect.height = 32;
    sfSprite_setTextureRect(game->p, rect);
    return (0);
}

int rect3_spt(sfrw *window, my_game_t *game, my_clock_t *c_anim)
{
    sfIntRect rect;
    rect.top = 96;
    rect.left = 0 + c_anim->i;
    rect.width = 32;
    rect.height = 32;
    sfSprite_setTextureRect(game->p, rect);
    return (0);
}