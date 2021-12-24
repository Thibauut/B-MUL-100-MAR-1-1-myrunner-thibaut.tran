/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_clock.c
*/

#include "../include/my.h"

all_clock_t init_clock(void)
{
    all_clock_t clock;
    clock.c_bg = create_clock();
    clock.c_run = create_clock();
    clock.c_jump = create_clock();
    clock.c_move = create_clock();
    clock.c_jump2 = create_clock();
    clock.c_obs = create_clock();
    return (clock);
}

void my_clock_anim(all_clock_t *clock)
{
    clock->c_bg.time = sfcget(clock->c_bg.clock);
    clock->c_bg.sec = clock->c_bg.time.m_sec / 1000000.0;
    clock->c_run.time = sfcget(clock->c_run.clock);
    clock->c_run.sec = clock->c_run.time.m_sec / 1000000.0;
    clock->c_jump.time = sfcget(clock->c_jump.clock);
    clock->c_jump.sec = clock->c_jump.time.m_sec / 1000000.0;
    clock->c_move.time = sfcget(clock->c_move.clock);
    clock->c_move.sec = clock->c_move.time.m_sec / 1000000.0;
    clock->c_jump2.time = sfcget(clock->c_jump2.clock);
    clock->c_jump2.sec = clock->c_jump2.time.m_sec / 1000000.0;
    clock->c_obs.time = sfcget(clock->c_obs.clock);
    clock->c_obs.sec = clock->c_obs.time.m_sec / 1000000.0;
}

void my_clock_restart(all_clock_t *clock)
{
    if (clock->c_bg.sec > 0.01) sfClock_restart(clock->c_bg.clock);
    if (clock->c_run.sec > 0.07) sfClock_restart(clock->c_run.clock);
}