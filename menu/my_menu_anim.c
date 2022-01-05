/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_menu_anim.c
*/

#include "../include/my.h"

int rect_bg(sfRenderWindow *window, my_menu_t *menu)
{
    sfIntRect rect;
    rect.top = 0 + menu->i;
    rect.left = 0 + menu->j;
    rect.width = 1920;
    rect.height = 1080;
    sfSprite_setTextureRect(menu->bg_menu, rect);
    sfRenderWindow_drawSprite(window, menu->bg_menu, NULL);
    return (0);
}

int my_bg_anim(sfrw *window, my_menu_t *menu, my_clock_t *c_bg)
{
    if (c_bg->sec > 0.18) {
        rect_bg(window, &*menu);
        menu->i += 1080;
        if (menu->i == 15120)
            menu->i = 0, menu->j += 1920;
        if (menu->j == 9600)
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