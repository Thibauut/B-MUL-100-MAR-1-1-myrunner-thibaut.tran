/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_player_anim.c
*/

#include "../include/my.h"

int spt_run(sfrw *window, my_game_t *game, my_clock_t *c_run)
{
    if (c_run->sec > 0.04) {
        rect_spt(window, &*game, &*c_run);
        c_run->i += 32;
        if (c_run->i>= 384)
            c_run->i= 0;
        sfClock_restart(c_run->clock);
    }
    return (0);
}

int spt_jump(my_clock_t *c_anim, my_map_t *map, my_game_t *game, sfrw *window)
{
    sfvf pos = {0, 12.5}, pos2 = {0, -12.5}, pos_p = sfsgp(game->p);
    if (c_anim->sec > 0.01678) {
        c_anim->i += 32;
        if (c_anim->i >= 1024) c_anim->i = 0, map->verif = 0;
        if (map->jump_verif != 0) {
            if (pos_p.y > 730) {
                sfsm(game->p, pos2), rect2_spt(window, &*game, &*c_anim);
                sfClock_restart(c_anim->clock); return (0);
            }
            map->jump_verif = 0;
        }
        if (map->jump_verif == 0) {
            if (pos_p.y < 930) {
                sfsm(game->p, pos), rect2_spt(window, &*game, &*c_anim);
                sfClock_restart(c_anim->clock); return (0);
            }
            map->jump_verif = 1;
        }
    }
    return (0);
}