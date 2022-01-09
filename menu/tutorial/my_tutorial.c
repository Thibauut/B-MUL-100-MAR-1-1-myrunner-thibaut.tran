/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_tutorial.c
*/

#include "../../include/my.h"

int clock_menu_anim(al_m_c *clock)
{
    clock->tuto_bg.time = sfcget(clock->c_bg.clock);
    clock->tuto_bg.sec = clock->tuto_bg.time.m_sec / 1000000.0;
    clock->press1.time = sfcget(clock->press1.clock);
    clock->press1.sec = clock->press1.time.m_sec / 1000000.0;
    return (0);
}

int print_tuto(sfrw *window, my_menu_t *menu, al_m_c *clock)
{
    sfEvent event;
    sfvi pos_mouse;
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        clock_menu_anim(&*clock);
        tuto_bg_anim(&*menu, &clock->tuto_bg, window);
        while (sfRenderWindow_pollEvent(window, &event)) {
            pos_mouse = sfMouse_getPositionRenderWindow(window);
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
            if (event.type == sfkp && event.key.code == sfKeySpace)
                return (0);
        }
        tuto_draw(window, &*menu);
        sfRenderWindow_display(window);
    }
    return (0);
}

int tuto_draw(sfrw *window, my_menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->bg_tuto, NULL);
    sfRenderWindow_drawSprite(window, menu->press_tuto, NULL);
    sfRenderWindow_drawSprite(window, menu->tutorial, NULL);
    return (0);
}

int tutorial(sfrw *w, ev event, sfvi pos_m, r_m *rect, m_t *menu, al_m_c *clock)
{
    if (sfFloatRect_contains(&rect->tuto, pos_m.x, pos_m.y)) {
        sfRenderWindow_clear(w, sfBlack);
        print_tuto(w, &*menu, &*clock);
    }
    return (0);
}