/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_score.c
*/

#include "../include/my.h"

int score(sfrw *window, my_clock_t *c_score, g *game)
{
    if (c_score->seconds > 0.5) {
        game->score_int += 1;
        sfClock_restart(c_score->clock);
    }
    return (0);
}