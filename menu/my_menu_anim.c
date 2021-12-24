/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_menu_anim.c
*/

#include "../include/my.h"

sfSprite *rect_bg(sfRenderWindow *window, spt *bg_menu, my_var_t *var)
{
    sfIntRect rect;
    rect.top = 0 + var->i;
    rect.left = 0 + var->j;
    rect.width = 1920;
    rect.height = 1080;
    sfSprite_setTextureRect(bg_menu, rect);
    sfRenderWindow_drawSprite(window, bg_menu, NULL);
    return (bg_menu);
}

sfSprite *my_bg_anim(sfrw *window, spt *bg_menu, float sec, my_var_t *var)
{
    if (sec > 0.18) {
        bg_menu = rect_bg(window, bg_menu, var);
        var->i += 1080;
        if (var->i == 15120)
            var->i = 0, var->j += 1920;
        if (var->j == 9600)
            var->j = 0;
    }
    return (bg_menu);
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