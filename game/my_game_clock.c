/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_clock.c
*/

#include "../include/my.h"

all_clock_t fill_clock(void)
{
    all_clock_t clock;
    clock.c_bg = my_init_clock();
    clock.c_run = my_init_clock();
    clock.c_jump = my_init_clock();
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
}

void my_clock_restart(all_clock_t *clock)
{
    if (clock->c_bg.sec > 0.01) sfClock_restart(clock->c_bg.clock);
    if (clock->c_run.sec > 0.07) sfClock_restart(clock->c_run.clock);
}