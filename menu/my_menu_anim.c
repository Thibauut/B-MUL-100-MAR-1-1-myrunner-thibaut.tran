/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_menu_anim.c
*/

#include "../include/my.h"

int my_bg_anim(sfrw *window, my_menu_t *menu, my_clock_t *c_bg)
{
    if (c_bg->sec > 0.11) {
        rect_bg(window, &*menu);
        menu->i += 1080;
        if (menu->i == 10800)
            menu->i = 0, menu->j += 1920;
        if (menu->j == 7680)
            menu->j = 0;
        sfClock_restart(c_bg->clock);
    }
    return (0);
}

int my_anim_but(sffr rect, sfvi pos_m, sfvf size, sfvf sizeup, spt *menu)
{
    sfSprite_setScale(menu, size);
    if (sfFloatRect_contains(&rect, pos_m.x, pos_m.y)) {
        sfFloatRect_contains(&rect, pos_m.x, pos_m.y);
        sfSprite_setScale(menu, sizeup);
    }
    return (0);
}