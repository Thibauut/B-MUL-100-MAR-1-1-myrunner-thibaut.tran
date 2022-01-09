/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game.c
*/

#include "../include/my.h"

int but_game(sfrw *window, my_game_t *game, my_map_t *map, all_clock_t *clock)
{
    sfEvent ev;
    sfVector2i pos_mouse;
    while (sfRenderWindow_pollEvent(window, &ev)) {
        player_verif(&ev, &*clock, &*map);
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        if (ev.type == sfec || (ev.type == sfkp && ev.key.code == sfKeyQ))
            sfRenderWindow_close(window);
    }
    if (map->verif == 1)
        spt_jump(&clock->c_jump, &*map, &*game, window);
    if (map->verif == 2)
        spt_atk(&clock->c_atk, &*map, &*game, window);
    return (0);
}

int my_game(sfrw *window, char *av, verif_inf_t *inf, music_t *music)
{
    all_clock_t clock = init_clock(); all_list_t list = init_list();
    my_map_t map; my_game_t game; collide_t collide;
    init_spt_game(&game), init_variable(&clock, &map, &game, &collide);
    check_obs(window, &map, &list, av); map.av = av;
    while (sfRenderWindow_isOpen(window)) {
        my_clock_anim(&clock), my_clock_anim2(&clock);
        bg_game_anim(window, &game, &clock.c_bg);
        score(window, &clock.c_score, &game);
        but_game(window, &game, &map, &clock);
        if (map.verif == 0)
            spt_run(window, &game, &clock.c_run);
        game.score_char = my_itoa(game.score_int);
        if (inf->i == 1 && sfSprite_getPosition(list.list_1->obs).x < -100)
            check_obs(window, &map, &list, av); map.av = av;
        if (inf->i == 0 && sfSprite_getPosition(list.list_1->obs).x < -100)
            print_win(window, &game, &collide, &map, inf, &*music);
        display_game(window, &game, &list, &clock, &collide, &map, inf, &*music);
    }
    return (0);
}

int display_game(sfrw *w, g *game, a_l *list, all_c *clock, c *c, m *map, v_t *inf, music_t *music)
{
    display_parallax(w, &*game);
    sfRenderWindow_drawSprite(w, game->p, NULL);
    display_obs(w, &*game, &*list, &*clock, &*c, &*map, inf, &*music);
    display_obs3(w, &*game, &*list, &*clock, &*c, &*map, inf, &*music);
    sfRenderWindow_drawSprite(w, game->bg_game_11, NULL);
    display_obs2(w, &*game, &*list, &*clock, &*c, &*map, inf, &*music);
    sfRenderWindow_drawSprite(w, game->score_text, NULL);
    sfText_setString(game->score_show, game->score_char);
    sfRenderWindow_drawText(w, game->score_show, NULL);
    sfRenderWindow_display(w);
    return (0);
}