/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_check_obs.c
*/

#include "../../include/my.h"


int anim_obs_1(sfrw *window, my_list_t *list, my_clock_t *c_obs_1)
{
    if (c_obs_1->sec > 0.05) {
        rect_obs_1(window, list, &*c_obs_1);
        c_obs_1->i += 32;
        if (c_obs_1->i == 448)
            c_obs_1->i = 0;
        sfClock_restart(c_obs_1->clock);
    }
    return (0);
}

int anim_obs_2(sfrw *window, my_list_t *list, my_clock_t *c_obs_2)
{
    if (c_obs_2->sec > 0.055) {
        rect_obs_2(window, list, &*c_obs_2);
        c_obs_2->i += 32;
        if (c_obs_2->i == 288)
            c_obs_2->i = 0;
        sfClock_restart(c_obs_2->clock);
    }
    return (0);
}

int anim_obs_3(sfrw *window, m_l *list, my_clock_t *c_obs_3, m *map, c *c)
{
    if (c_obs_3->sec > 0.07) {
        if (map->verif == 0 && c->verif == 0) {
            rect_obs_3(window, list, &*c_obs_3);
            c_obs_3->i += 32;
            if (c_obs_3->i == 96)
                c_obs_3->i = 0;
        }
        sfClock_restart(c_obs_3->clock);
    }
    return (0);
}

int anim_obs_3_1(sfrw *window, m_l *list, my_clock_t *c_obs_3_1, m *map, c *c)
{
    if (c_obs_3_1->sec > 0.03) {
        rect_obs_3_1(window, list, &*c_obs_3_1);
        c_obs_3_1->i += 32;
        if (c_obs_3_1->i > 224) {
            c_obs_3_1->i = 0, c->verif = 0;
            return (0);
        }
        sfClock_restart(c_obs_3_1->clock);
    }
    return (0);
}