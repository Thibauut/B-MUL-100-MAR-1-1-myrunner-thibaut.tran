/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_move_obs.c
*/

#include "../../include/my.h"

int move_obs(sfrw *window, my_list_t *list, my_clock_t *c_obs)
{
    sfvf pos = {-10.4, 0}, pos_o = sfSprite_getPosition(list->obs);
    if (c_obs->sec > 0.01) {
        if (pos_o.x != -100)
            sfSprite_move(list->obs, pos);
        sfClock_restart(c_obs->clock);
    }
    return (0);
}

int move_obs2(sfrw *window, my_list_t *list, my_clock_t *c_obs)
{
    sfvf pos = {-11, 0}, pos_o = sfSprite_getPosition(list->obs);
    if (c_obs->sec > 0.01) {
        if (pos_o.x != -100)
            sfSprite_move(list->obs, pos);
        sfClock_restart(c_obs->clock);
    }
    return (0);
}

int move_obs3(sfrw *window, my_list_t *list, my_clock_t *c_obs)
{
    sfvf pos = {-10, 0}, pos_o = sfSprite_getPosition(list->obs);
    if (c_obs->sec > 0.01) {
        if (pos_o.x != -100)
            sfSprite_move(list->obs, pos);
        sfClock_restart(c_obs->clock);
    }
    return (0);
}