/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_anim.c
*/

#include "../include/my.h"

void bg_game(sfrw *window, my_game_t *game, my_var_t *var)
{
    rect_bg_game(window, &*game, var);
    var->i += 2;
    if (var->i >= 1920)
        var->i = 0;
    rect_bg2_game(window, &*game, var);
    var->j += 4;
    if (var->j >= 1920)
        var->j = 0;
    rect_bg3_game(window, &*game, var);
    var->k += 5;
    if (var->k >= 1920)
        var->k = 0;
    return;
}

void bg_game_anim(sfrw *window, my_game_t *game, float sec, my_var_t *var)
{
    if (seconds > 0.01) {
        bg_game(window, &*game, var);
    }
    return;
}