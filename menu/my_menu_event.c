/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_menu_event.c
*/

#include "../include/my.h"

int print_launch(sfrw *window, my_menu_t *menu, music_t *music)
{
    music->game = sfMusic_createFromFile("res/game/game.ogg");
    sfMusic_setVolume(music->game, 50);
    sfMusic_setLoop(music->game, sfTrue);
    sfMusic_play(music->game);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_drawSprite(window, menu->launch, NULL);
    sfRenderWindow_display(window);
    return (0);
}

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

int my_event_play(sfrw *w, ev event, sfvi pos_m, r_m *rect, char *av, m_t *menu, al_m_c *clock, verif_inf_t *inf, music_t *music)
{
    if (event.type == sfEvtMouseButtonPressed) {
        if (sfFloatRect_contains(&rect->play, pos_m.x, pos_m.y)) {
            print_launch(w, &*menu, &*music);
            while (sfRenderWindow_waitEvent(w, &event)) {
                if (event.type == sfEvtClosed)
                    sfRenderWindow_close(w);
                if (event.type == sfkp && event.key.code == sfKeySpace) {
                    sfRenderWindow_clear(w, sfBlack);
                    init_game(w, av, inf, &*music);
                    // my_game(w, av, inf, &*music);
                }
            }
        }
        tutorial(w, event, pos_m, &*rect, &*menu, &*clock);
    }
    return (0);
}