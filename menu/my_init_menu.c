/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_init_menu.c
*/

#include "../include/my.h"

void init_sprite_menu(my_menu_t *menu)
{
    menu->bg_menu = create_sprite("res/menu/bg2.png", -1, 0, 1.02, 1);
    menu->title = create_sprite("res/menu/title.png", 190, 80, 0.8, 0.9);
    menu->play = create_sprite("res/menu/play.png", 800, 655, 0.4, 0.4);
    menu->exit = create_sprite("res/menu/exit.png", 810, 800, 0.4, 0.4);
    menu->option = create_sprite("res/menu/option.png", 1560, 870, 0.27, 0.27);
}

void init_menu_variable(my_menu_t *menu)
{
    menu->i = 0;
    menu->j = 0;
    menu->k = 0;
}