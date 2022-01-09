/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_menu.c
*/

#include "../include/my.h"

int but_menu(sfrw *window, m_t menu, char *av, r_m *rect, al_m_c *clock, verif_inf_t *inf, music_t *music)
{
    sfEvent event;
    sfvi pos_mouse;
    sfvf size = {0.4, 0.4}, sizeup = {0.405, 0.405};
    sfvf size2 = {0.27, 0.27}, sizeup2 = {0.275, 0.275};
    rect = init_rect(&*rect, menu);
    while (sfRenderWindow_pollEvent(window, &event)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        my_anim_but(rect->play, pos_mouse, size, sizeup, menu.play);
        my_anim_but(rect->exit, pos_mouse, size, sizeup, menu.exit);
        my_anim_but(rect->option, pos_mouse, size2, sizeup2, menu.option);
        my_anim_but(rect->tuto, pos_mouse, size2, sizeup2, menu.tuto);
        my_event_close(window, event, pos_mouse, rect->exit);
        my_event_play(window, event, pos_mouse, &*rect, av, &menu, &*clock, inf, &*music);
    }
    return (0);
}

int my_menu(sfRenderWindow *window, char *av, verif_inf_t *inf)
{
    all_menu_clock_t clock = init_clock_menu();
    my_menu_t menu; r_menu_t rect; music_t music;
    init_sprite_menu(&menu), init_menu_variable(&menu);
    while (sfRenderWindow_isOpen(window)) {
        clock.c_bg.time = sfcget(clock.c_bg.clock);
        clock.c_bg.sec = clock.c_bg.time.m_sec / 1000000.0;
        but_menu(window, menu, av, &rect, &clock, inf, &music);
        my_bg_anim(window, &menu, &clock.c_bg);
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
    sfRenderWindow_drawSprite(window, menu.tuto, NULL);
    sfRenderWindow_display(window);
    return (0);
}
