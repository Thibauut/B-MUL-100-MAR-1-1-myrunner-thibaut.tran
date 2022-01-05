/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_anim.c
*/

#include "../include/my.h"

void bg_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    rect_bg_game(window, &*game, c_bg);
    c_bg->i += 2;
    if (c_bg->i >= 1920)
        c_bg->i = 0;
    rect_bg2_game(window, &*game, c_bg);
    c_bg->j += 4;
    if (c_bg->j >= 1920)
        c_bg->j = 0;
    rect_bg3_game(window, &*game, c_bg);
    c_bg->k += 7;
    if (c_bg->k >= 1920)
        c_bg->k = 0;
    return;
}

void bg_game_anim(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    if (c_bg->sec > 0.01) {
        bg_game(window, &*game, &*c_bg);
        sfClock_restart(c_bg->clock);
    }
    return;
}