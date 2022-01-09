/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_anim.c
*/

#include "../include/my.h"

int bg_game(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    rect_bg_game(window, &*game, c_bg);
    c_bg->i += 1;
    if (c_bg->i >= 1920)
        c_bg->i = 0;
    rect_bg2_game(window, &*game, c_bg);
    c_bg->j += 2;
    if (c_bg->j >= 1920)
        c_bg->j = 0;
    rect_bg3_game(window, &*game, c_bg);
    c_bg->k += 3;
    if (c_bg->k >= 1920)
        c_bg->k = 0;
    return (0);
}

int bg_game2(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    rect_bg4_game(window, &*game, c_bg);
    c_bg->l += 4;
    if (c_bg->l >= 1920)
        c_bg->l = 0;
    rect_bg5_game(window, &*game, c_bg);
    c_bg->n += 5;
    if (c_bg->n >= 1920)
        c_bg->n = 0;
    rect_bg6_game(window, &*game, c_bg);
    c_bg->o += 6;
    if (c_bg->o >= 1920)
        c_bg->o = 0;
    rect_bg7_game(window, &*game, c_bg);
    c_bg->p += 7;
    if (c_bg->p >= 1920)
        c_bg->p = 0;
    return (0);
}

int bg_game3(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    rect_bg8_game(window, &*game, c_bg);
    c_bg->q += 8;
    if (c_bg->q >= 1920)
        c_bg->q = 0;
    rect_bg9_game(window, &*game, c_bg);
    c_bg->r += 9;
    if (c_bg->r >= 1920)
        c_bg->r = 0;
    rect_bg10_game(window, &*game, c_bg);
    c_bg->s += 10;
    if (c_bg->s >= 1920)
        c_bg->s = 0;
    rect_bg11_game(window, &*game, c_bg);
    c_bg->y += 10;
    if (c_bg->y >= 1920)
        c_bg->y = 0;
    return (0);
}

int bg_game_anim(sfrw *window, my_game_t *game, my_clock_t *c_bg)
{
    if (c_bg->sec > 0.01) {
        bg_game(window, &*game, &*c_bg);
        bg_game2(window, &*game, &*c_bg);
        bg_game3(window, &*game, &*c_bg);
        sfClock_restart(c_bg->clock);
    }
    return (0);
}