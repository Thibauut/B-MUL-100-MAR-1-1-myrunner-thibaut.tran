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

int but_menu(sfrw *window, my_menu_t menu, char *av)
{
    sfEvent event;
    sfvi pos_mouse;
    sfvf size = {0.4, 0.4}, sizeup = {0.405, 0.405};
    sfvf size2 = {0.27, 0.27}, sizeup2 = {0.275, 0.275};
    sfFloatRect play = sfSprite_getGlobalBounds(menu.play);
    sfFloatRect exit = sfSprite_getGlobalBounds(menu.exit);
    sfFloatRect option = sfSprite_getGlobalBounds(menu.option);
    while (sfRenderWindow_pollEvent(window, &event)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        my_anim_but(play, pos_mouse, size, sizeup, menu.play);
        my_anim_but(exit, pos_mouse, size, sizeup, menu.exit);
        my_anim_but(option, pos_mouse, size2, sizeup2, menu.option);
        my_event_close(window, event, pos_mouse, exit);
        my_event_play(window, event, pos_mouse, play, av);
    }
    return (0);
}

int my_menu(sfRenderWindow *window, char *av)
{
    my_clock_t c_bg = {sfClock_create(), 0, 0};
    my_menu_t menu;
    init_sprite_menu(&menu), init_menu_variable(&menu);
    while (sfRenderWindow_isOpen(window)) {
        c_bg.time = sfcget(c_bg.clock), c_bg.sec = c_bg.time.m_sec / 1000000.0;
        but_menu(window, menu, av);
        my_bg_anim(window, &menu, &c_bg);
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
