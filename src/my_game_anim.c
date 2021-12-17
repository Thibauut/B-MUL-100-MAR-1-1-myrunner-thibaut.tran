/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_anim.c
*/

#include "../include/my.h"

my_game_t my_bg_game(sfrw *window, my_game_t game, my_var_t *var)
{
    game.bg_game = rect_bg_game(window, game, var);
    var->i += 2;
    if (var->i >= 1920)
        var->i = 0;
    game.bg_game_2 = rect_bg2_game(window, game, var);
    var->j += 4;
    if (var->j >= 1920)
        var->j = 0;
    game.bg_game_3 = rect_bg3_game(window, game, var);
    var->k += 5;
    if (var->k >= 1920)
        var->k = 0;
    return (game);
}

my_game_t my_ronin_game(sfrw *window, my_game_t game, my_var_t *var)
{
    game.ronin = rect_ronin(window, game, var);
    var->m += 64;
    if (var->m >= 640)
        var->m = 0;
    return (game);
}

my_game_t bg_game_anim(sfrw *window, my_game_t game, float sec, my_var_t *var)
{
    if (seconds > 0.01) {
        game = my_bg_game(window, game, var);
    }
    return (game);
}


my_game_t ronin_anim(sfrw *window, my_game_t game, float sec, my_var_t *var)
{
    if (seconds > 0.07) {
        game = my_ronin_game(window, game, var);
    }
    return (game);
}