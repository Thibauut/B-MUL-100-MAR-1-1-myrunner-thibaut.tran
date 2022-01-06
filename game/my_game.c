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

int my_game(sfrw *window, char *av)
{
    all_clock_t clock = init_clock(); my_map_t map; my_game_t game;
    all_list_t list = init_list();
    collide_t collide;
    init_spt_game(&game), init_variable(&clock, &map, &game);
    check_obs(window, &map, &list, av);
    while (sfRenderWindow_isOpen(window)) {
        my_clock_anim(&clock), my_clock_anim2(&clock);
        bg_game_anim(window, &game, &clock.c_bg);
        but_game(window, &game, &map, &clock);
        if (map.verif == 0)
            spt_run(window, &game, &clock.c_run);
        display_game(window, &game, &list, &clock, &collide);
    }
    return (0);
}

int display_obs(sfrw *w, my_game_t *game, all_list_t *list, all_c *clock, c *c)
{
    my_list_t *obs_1 = malloc(sizeof(my_list_t));
    obs_1 = list->list_1;
    for (; obs_1 != NULL; obs_1 = obs_1->next) {
        anim_obs_1(w, obs_1, &clock->c_obs_1);
        move_obs(w, obs_1, &clock->c_obs);
        collision_1(obs_1, &*game, w, &*c);
        sfRenderWindow_drawSprite(w, obs_1->obs, NULL);
    }
    my_list_t *obs_2 = malloc(sizeof(my_list_t));
    obs_2 = list->list_2;
    for (; obs_2 != NULL; obs_2 = obs_2->next) {
        anim_obs_2(w, obs_2, &clock->c_obs_2);
        move_obs2(w, obs_2, &clock->c_obs);
        collision_2(obs_2, &*game, w, &*c);
        sfRenderWindow_drawSprite(w, obs_2->obs, NULL);
    }
    return (0);
}

int display_obs2(sfrw *w, my_game_t *game, all_list_t *list, all_c *clock, c *c)
{
    my_list_t *obs_3 = malloc(sizeof(my_list_t));
    obs_3 = list->list_3;
    for (; obs_3 != NULL; obs_3 = obs_3->next) {
        anim_obs_3(w, obs_3, &clock->c_obs_3);
        move_obs(w, obs_3, &clock->c_obs);
        // collision_3(obs_3, &*game, w, &*c);
        sfRenderWindow_drawSprite(w, obs_3->obs, NULL);
    }
    return (0);
}

int display_game(sfrw *w, my_game_t *game, all_list_t *list, all_c *clock, c *c)
{
    sfRenderWindow_drawSprite(w, game->bg_game, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_2, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_3, NULL);
    sfRenderWindow_drawSprite(w, game->p, NULL);
    display_obs(w, &*game, &*list, &*clock, &*c);
    display_obs2(w, &*game, &*list, &*clock, &*c);
    sfRenderWindow_display(w);
    return (0);
}