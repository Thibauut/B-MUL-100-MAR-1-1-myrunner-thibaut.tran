/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_menu_event.c
*/

#include "../include/my.h"

int my_event_close(sfrw *window, sfEvent event, sfvi pos_m, sffr rect)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonPressed) {
        pos_m = sfMouse_getPositionRenderWindow(window);
        if (sfFloatRect_contains(&rect, pos_m.x, pos_m.y))
            sfRenderWindow_close(window);
    }
    return (0);
}

int my_event_play(sfrw *window, sfEvent event, sfvi pos_m, sffr play, char *av)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&play, pos_m.x, pos_m.y)) {
            sfRenderWindow_clear(window, sfBlack);
            my_game(window, av);
        }
    }
    return (0);
}