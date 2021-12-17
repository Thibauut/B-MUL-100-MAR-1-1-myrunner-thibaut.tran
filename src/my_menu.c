/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_menu.c
*/

#include "../include/my.h"

int my_init_menu(char *av)
{
    sfRenderWindow *window = create_window(1920, 1080, 32, "MY RUNNER");
    sfRenderWindow_setFramerateLimit(window, 60);
    my_menu(window, av);
    return (0);
}

int my_button(sfrw *window, my_menu_t menu, char *av)
{
    sfEvent event;
    sfVector2i pos_mouse;
    sfVector2f size = {0.4, 0.4}, sizeup = {0.405, 0.405};
    sfFloatRect play = sfSprite_getGlobalBounds(menu.play);
    sfFloatRect exit = sfSprite_getGlobalBounds(menu.exit);
    sfFloatRect option = sfSprite_getGlobalBounds(menu.option);
    while (sfRenderWindow_pollEvent(window, &event)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        my_anim_but(play, pos_mouse, size, sizeup, menu.play);
        my_anim_but(exit, pos_mouse, size, sizeup, menu.exit);
        // my_anim_but(option, pos_mouse, size, sizeup, menu.option);
        my_event_close(window, event, pos_mouse, exit);
        my_event_play(window, event, pos_mouse, play, av);
    }
    return (0);
}

int my_menu(sfRenderWindow *window, char *av)
{
    my_clock_t c_bg = {sfClock_create(), 0, 0};
    my_var_t *var = malloc(sizeof(my_var_t));
    var->i = 0, var->j = 0;
    my_menu_t menu;
    menu.bg_menu = create_sprite("res/menu/bg2.png", 0, 0, 1, 1);
    menu.title = create_sprite("res/menu/title.png", 190, 120, 0.8, 0.9);
    menu.play = create_sprite("res/menu/play.png", 800, 655, 0.4, 0.4);
    menu.exit = create_sprite("res/menu/exit.png", 810, 800, 0.4, 0.4);
    menu.option = create_sprite("res/menu/option.png", 1560, 870, 0.27, 0.27);
    while (sfRenderWindow_isOpen(window)) {
        c_bg.time = sfcget(c_bg.clock), c_bg.sec = c_bg.time.m_sec / 1000000.0;
        my_button(window, menu, av);
        menu.bg_menu = my_bg_anim(window, menu.bg_menu, c_bg.sec, var);
        if (c_bg.sec > 0.18)
            sfClock_restart(c_bg.clock);
        display_menu(window, menu);
    }
    return (0);
}

int display_menu(sfRenderWindow *window, my_menu_t menu)
{
    sfRenderWindow_drawSprite(window, menu.bg_menu, NULL);
    sfRenderWindow_drawSprite(window, menu.title, NULL);
    sfRenderWindow_drawSprite(window, menu.play, NULL);
    sfRenderWindow_drawSprite(window, menu.exit, NULL);
    sfRenderWindow_drawSprite(window, menu.option, NULL);
    sfRenderWindow_display(window);
    return (0);
}
