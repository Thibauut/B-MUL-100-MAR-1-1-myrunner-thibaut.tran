/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_tutorial_anim.c
*/

#include "../../include/my.h"

int tuto_bg_anim(my_menu_t *menu, my_clock_t *clock, sfrw *window)
{
    if (clock->seconds > 0.1) {
        menu->l += 2;
        if (menu->l >= 1920)
            menu->l = 0;
        sfClock_restart(clock->clock);
    }
    rect_tuto_bg(&*menu);
    return (0);
}