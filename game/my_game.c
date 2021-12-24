/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game.c
*/

#include "../include/my.h"

int init_game(sfrw *window, char *av)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    my_game(window, av);
    return (0);
}

void init_spt_game(my_game_t *game, my_obs_t *obs)
{
    game->bg_game = create_sprite("res/game/bg_game.png", 0, 0, 1, 1);
    game->bg_game_2 = create_sprite("res/game/bg_game_2.png", 0, -100, 1, 1);
    game->bg_game_3 = create_sprite("res/game/bg_game_3.png", 0, 60, 1, 1);
    game->ronin = create_sprite("res/sprite/frog.png", 20, 930, 3.5, 3.5);
    return;
}

int but_game(sfrw *window, my_game_t *game, my_map_t *map, all_clock_t *clock)
{
    sfEvent ev;
    sfVector2i pos_mouse;
    while (sfRenderWindow_pollEvent(window, &ev)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        if (ev.type == sfec || (ev.type == sfkp && ev.key.code == sfKeyQ))
            sfRenderWindow_close(window);
        map->verif = player_verif(ev, &*clock, &*map);
    }
    if (map->verif == 1)
        spt_jump(&clock->c_jump, &*map, &*game, window);
    return (0);
}

int my_game(sfrw *window, char *av)
{
    all_clock_t clock = init_clock(); my_map_t map; my_obs_t obs; my_game_t game;
    my_var_t *var = malloc(sizeof(my_var_t));
    var->i = 0, var->j = 0, var->k = 0, var->m = 0;
    init_spt_game(&game, &obs);
    check_map(window, &map, &obs, av), map.verif = 0;
    while (sfRenderWindow_isOpen(window)) {
        my_clock_anim(&clock);
        bg_game_anim(window, &game, clock.c_bg.sec, var);
        if (map.verif == 0) spt_run(window, &game, clock.c_run.sec, var);
        but_game(window, &game, &map, &clock);
        move_obs(window, &obs, &clock.c_obs);
        my_clock_restart(&clock);
        display_game(window, &game, &obs);
    }
    return (0);
}

int display_game(sfrw *window, my_game_t *game, my_obs_t *obs)
{
    sfRenderWindow_drawSprite(window, game->bg_game, NULL);
    sfRenderWindow_drawSprite(window, game->bg_game_2, NULL);
    sfRenderWindow_drawSprite(window, game->bg_game_3, NULL);
    sfRenderWindow_drawSprite(window, game->ronin, NULL);
    sfRenderWindow_drawSprite(window, obs->obs_s, NULL);
    sfRenderWindow_display(window);
    return (0);
}