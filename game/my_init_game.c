/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_init_game.c
*/

#include "../include/my.h"
#define clr sfColor_fromRGB

int init_game(sfrw *window, char *av, verif_inf_t *inf, music_t *music)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    my_game(window, av, inf, music);
    return (0);
}

int init_spt_game(my_game_t *game)
{
    game->bg_game_1 = create_sprite("res/game/10.png", 0, 0, 1, 1);
    game->bg_game_2 = create_sprite("res/game/9.png", 0, 0, 1, 1);
    game->bg_game_3 = create_sprite("res/game/8.png", 0, 0, 1, 1);
    game->bg_game_4 = create_sprite("res/game/7.png", 0, 0, 1, 1);
    game->bg_game_5 = create_sprite("res/game/6.png", 0, 0, 1, 1);
    game->bg_game_6 = create_sprite("res/game/5.png", 0, 0, 1, 1);
    game->bg_game_7 = create_sprite("res/game/4.png", 0, 0, 1, 1);
    game->bg_game_8 = create_sprite("res/game/3.png", 0, 0, 1, 1);
    game->bg_game_9 = create_sprite("res/game/2.png", 0, 0, 1, 1);
    game->bg_game_10 = create_sprite("res/game/1.png", 0, 0, 1, 1);
    game->bg_game_11 = create_sprite("res/game/11.png", 0, 0, 1, 1);
    game->p = create_sprite("res/sprite/frog.png", 100, 749, 3.5, 3.5);
    game->lose = create_sprite("res/game/gameover.png", 0, 0, 1, 1);
    game->score_text = create_sprite("res/game/score.png", -500, -337, 0.7, 0.7);
    game->score_show = create_text(game->score_char, 70, clr(239, 182, 151), 320, 16, clr(165, 113, 85));
    game->win = create_sprite("res/game/win.png", 0, 0, 1, 1);
    return (0);
}

int init_variable(all_clock_t *clock, my_map_t *map, my_game_t *game, c *c)
{
    game->i = 0, map->verif = 0, map->jump_verif = 0;
    clock->c_bg.i = 0, clock->c_bg.j = 0, clock->c_bg.k = 0;
    clock->c_bg.l = 0, clock->c_bg.n = 0, clock->c_bg.o = 0;
    clock->c_bg.p = 0, clock->c_bg.q = 0, clock->c_bg.r = 0;
    clock->c_bg.s = 0, clock->c_bg.y = 0, clock->c_obs_1.i = 0;
    clock->c_obs_2.i = 0, clock->c_run.i = 0, clock->c_jump.i = 0;
    clock->c_atk.i = 0, clock->c_obs_3.i = 0, clock->c_obs_3_1.i = 0;
    clock->c_obs_3_1.j = 0, c->verif = 0, c->lose = 0, game->tmp = 0;
    game->tmp2 = 0, game->tmp3 = 0, game->kill = 5, game->score_int = 0;;
    return (0);
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
    clock.c_atk = create_clock();
    clock.c_obs_3 = create_clock();
    clock.c_obs_3_1 = create_clock();
    clock.c_score = create_clock();
    return (clock);
}