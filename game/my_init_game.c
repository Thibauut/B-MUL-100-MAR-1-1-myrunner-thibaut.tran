/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_init_game.c
*/

#include "../include/my.h"

int init_game(sfrw *window, char *av)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    my_game(window, av);
    return (0);
}

void init_spt_game(my_game_t *game)
{
    game->bg_game = create_sprite("res/game/bg_game.png", 0, 0, 1, 1);
    game->bg_game_2 = create_sprite("res/game/bg_game_2.png", 0, -100, 1, 1);
    game->bg_game_3 = create_sprite("res/game/bg_game_3.png", 0, 60, 1, 1);
    game->p = create_sprite("res/sprite/frog.png", 20, 930, 3.5, 3.5);
    return;
}

void init_variable(all_clock_t *clock, my_map_t *map, my_game_t *game)
{
    game->i = 0;
    map->verif = 0;
    map->jump_verif = 0;
    clock->c_bg.i = 0;
    clock->c_bg.j = 0;
    clock->c_bg.k = 0;
    clock->c_obs_1.i = 0;
    clock->c_obs_2.i = 0;
    clock->c_run.i = 0;
    clock->c_jump.i = 0;
}

all_clock_t init_clock(void)
{
    all_clock_t clock;
    clock.c_bg = create_clock();
    clock.c_run = create_clock();
    clock.c_jump = create_clock();
    clock.c_move = create_clock();
    clock.c_jump2 = create_clock();
    clock.c_obs = create_clock();
    clock.c_obs_1 = create_clock();
    clock.c_obs_2 = create_clock();
    return (clock);
}