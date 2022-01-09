/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_loose.c
*/

#include "../include/my.h"

int print_lose(sfrw *window, g *game, c *c, m *map, verif_inf_t *inf, music_t *music)
{
    sfEvent event; sfvi pos_mouse;
    sfMusic_destroy(music->game);
    sfvf score_pos = {1060, 605}, score_pos2 = {230, 250};
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            pos_mouse = sfMouse_getPositionRenderWindow(window);
            if (event.type == sfkp && sfkey(sfKeySpace))
                my_menu(window, map->av, inf);
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_drawSprite(window, game->lose, NULL);
        sfText_setPosition(game->score_show, score_pos);
        sfSprite_setPosition(game->score_text, score_pos2);
        sfRenderWindow_drawSprite(window, game->score_text, NULL);
        sfRenderWindow_drawText(window, game->score_show, NULL);
        sfRenderWindow_display(window);
    }
    return (0);
}

int print_win(sfrw *window, g *game, c *c, m *map, verif_inf_t *inf, music_t *music)
{
    sfEvent event; sfvi pos_mouse;
    sfMusic_destroy(music->game);
    sfvf score_pos = {1040, 605}, score_pos2 = {210, 250};
    sfRenderWindow_setFramerateLimit(window, 60);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            pos_mouse = sfMouse_getPositionRenderWindow(window);
            if (event.type == sfkp && sfkey(sfKeySpace))
                my_menu(window, map->av, inf);
            if (event.type == sfEvtClosed)
                sfRenderWindow_close(window);
        }
        sfRenderWindow_drawSprite(window, game->win, NULL);
        sfText_setPosition(game->score_show, score_pos);
        sfSprite_setPosition(game->score_text, score_pos2);
        sfRenderWindow_drawSprite(window, game->score_text, NULL);
        sfRenderWindow_drawText(window, game->score_show, NULL);
        sfRenderWindow_display(window);
    }
    return (0);
}