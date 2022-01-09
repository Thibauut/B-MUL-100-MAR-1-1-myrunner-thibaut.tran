/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_menu_rect.c
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
    return (0);
}

int rect_tuto_bg(my_menu_t *menu)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + menu->l;
    rect.width = 1920;
    rect.height = 1080;
    sfSprite_setTextureRect(menu->bg_tuto, rect);
    return (0);
}