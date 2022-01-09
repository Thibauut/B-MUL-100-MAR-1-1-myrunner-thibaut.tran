/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_clock.c
*/

#include "../include/my.h"

int my_clock_anim(all_clock_t *clock)
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
    clock->c_obs_1.time = sfcget(clock->c_obs_1.clock);
    clock->c_obs_1.sec = clock->c_obs_1.time.m_sec / 1000000.0;
    clock->c_obs_2.time = sfcget(clock->c_obs_2.clock);
    clock->c_obs_2.sec = clock->c_obs_2.time.m_sec / 1000000.0;
    clock->c_atk.time = sfcget(clock->c_atk.clock);
    clock->c_atk.sec = clock->c_atk.time.m_sec / 1000000.0;
    return (0);
}

int my_clock_anim2(all_clock_t *clock)
{
    clock->c_obs_3.time = sfcget(clock->c_obs_3.clock);
    clock->c_obs_3.sec = clock->c_obs_3.time.m_sec / 1000000.0;
    clock->c_obs_3_1.time = sfcget(clock->c_obs_3_1.clock);
    clock->c_obs_3_1.sec = clock->c_obs_3_1.time.m_sec / 1000000.0;
    clock->c_score.time = sfcget(clock->c_score.clock);
    clock->c_score.sec = clock->c_score.time.m_sec / 1000000.0;
    return (0);
}