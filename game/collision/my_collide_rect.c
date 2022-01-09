/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** rect_collide.c
*/

#include "../../include/my.h"

int ajust_rect_p(sfFloatRect *rect_p, sfFloatRect *rect_p_2)
{
    rect_p->width -= 37;
    rect_p->height -= 65;
    rect_p->top += 10;
    rect_p->left += 10;
    rect_p_2->width -= 58;
    rect_p_2->height -= 65;
    rect_p_2->top += 45;
    rect_p_2->left += 20.5;
    return (0);
}

int ajust_rect_atk(sfFloatRect *rect_p, sfFloatRect *rect_p_2, sffr *rect_p_3)
{
    rect_p->width -= 37;
    rect_p->height -= 65;
    rect_p->top += 10;
    rect_p->left += 10;
    rect_p_2->width -= 58;
    rect_p_2->height -= 65;
    rect_p_2->top += 45;
    rect_p_2->left += 20.5;
    rect_p_3->width -= 58;
    rect_p_3->height -= 90;
    rect_p_3->top += 47;
    rect_p_3->left += 55;
    return (0);
}

int ajust_rect_obs_1(sfFloatRect *rect_obs_1, sfFloatRect *rect_obs_1_1)
{
    rect_obs_1->width -= 50;
    rect_obs_1->height -= 25;
    rect_obs_1->top += 10;
    rect_obs_1->left += 3;
    rect_obs_1_1->width -= 45;
    rect_obs_1_1->height -= 45;
    rect_obs_1_1->top += 20;
    rect_obs_1_1->left += 15;
    return (0);
}

int ajust_rect_obs_2(sfFloatRect *rect_obs_2, sfFloatRect *rect_obs_2_1)
{
    rect_obs_2->width -= 45;
    rect_obs_2->height -= 23;
    rect_obs_2->top += 7;
    rect_obs_2->left += 15;
    rect_obs_2_1->width -= 40;
    rect_obs_2_1->height -= 53;
    rect_obs_2_1->top += 14;
    rect_obs_2_1->left -= 1;
    return (0);
}

int ajust_rect_obs_3(sfFloatRect *rect_obs_3, sfFloatRect *rect_obs_3_1)
{
    rect_obs_3->width -= 70;
    rect_obs_3->height -= 65;
    rect_obs_3->top += 45;
    rect_obs_3->left += 33;
    rect_obs_3_1->width -= 85;
    rect_obs_3_1->height -= 65;
    rect_obs_3_1->top += 28;
    rect_obs_3_1->left += 45;
    return (0);
}