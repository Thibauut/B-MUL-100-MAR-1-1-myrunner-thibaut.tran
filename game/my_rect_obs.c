/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_rect_obs.c
*/

#include "../include/my.h"

void rect_obs_1(sfrw *window, my_list_t *list, my_clock_t *c_obs_1)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_obs_1->i;
    rect.width = 32;
    rect.height = 34;
    sfSprite_setTextureRect(list->obs, rect);
}

void rect_obs_2(sfrw *window, my_list_t *list, my_clock_t *c_obs_2)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + c_obs_2->i;
    rect.width = 32;
    rect.height = 32;
    sfSprite_setTextureRect(list->obs, rect);
}