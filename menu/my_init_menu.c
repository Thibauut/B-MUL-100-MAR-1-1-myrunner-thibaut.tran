/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_init_menu.c
*/

#include "../include/my.h"

int my_init_menu(char *av, verif_inf_t *inf)
{
    sfRenderWindow *window = create_window(1920, 1080, 32, "MY RUNNER");
    sfRenderWindow_setFramerateLimit(window, 60);
    my_menu(window, av, inf);
    return (0);
}

int init_sprite_menu(my_menu_t *menu)
{
    menu->bg_menu = create_sprite("res/menu/menu.png", 0, 0, 1, 1);
    menu->title = create_sprite("res/menu/title.png", 190, 80, 0.8, 0.9);
    menu->play = create_sprite("res/menu/play.png", 800, 655, 0.4, 0.4);
    menu->exit = create_sprite("res/menu/exit.png", 810, 800, 0.4, 0.4);
    menu->option = create_sprite("res/menu/option.png", 1550, 960, 0.27, 0.27);
    menu->tuto = create_sprite("res/menu/tutorial.png", 60, 960, 0.27, 0.27);
    menu->tutorial = create_sprite("res/menu/parallax.png", 0, 0, 1, 1);
    menu->bg_tuto = create_sprite("res/menu/tuto_bg.png", 0, 0, 1, 1);
    menu->press_tuto = create_sprite("res/menu/press1.png", 545, 900, 0.7, 0.7);
    menu->launch = create_sprite("res/menu/launch.png", 0, 0, 1, 1);
    return (0);
}

all_menu_clock_t init_clock_menu(void)
{
    all_menu_clock_t clock;
    clock.c_bg = create_clock();
    clock.tuto_bg = create_clock();
    clock.press1 = create_clock();
    return (clock);
}

int init_menu_variable(my_menu_t *menu)
{
    menu->i = 0;
    menu->j = 0;
    menu->k = 0;
    menu->l = 0;
    return (0);
}

r_menu_t *init_rect(r_menu_t *rect, my_menu_t menu)
{
    rect->play = sfSprite_getGlobalBounds(menu.play);
    rect->exit = sfSprite_getGlobalBounds(menu.exit);
    rect->option = sfSprite_getGlobalBounds(menu.option);
    rect->tuto = sfSprite_getGlobalBounds(menu.tuto);
    return (rect);
}