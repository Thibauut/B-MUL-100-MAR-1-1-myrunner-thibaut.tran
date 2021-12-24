/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_player_anim.c
*/

#include "../include/my.h"

void spt_run(sfrw *window, my_game_t *game, float sec, my_var_t *var)
{
    if (seconds > 0.065) {
        rect_ronin(window, &*game, var);
        var->m += 32;
        if (var->m >= 384)
            var->m = 0;
    }
    return;
}

int spt_jump(my_clock_t *c_anim, my_map_t *map, my_game_t *game, sfrw *window)
{
    sfvf pos = {0, 12.5}, pos2 = {0, -12.5}, pos_p = sfSprite_getPosition(game->ronin);
    if (c_anim->sec > 0.01664) {
        c_anim->i += 32;
        if (c_anim->i >= 1024) c_anim->i = 0, map->verif = 0;
        if (map->jump_verif == 0) {
            if (pos_p.y > 730) {
                sfSprite_move(game->ronin, pos2), rect2_spt(window, &*game, &*c_anim);
                sfClock_restart(c_anim->clock); return (0);
            }
            map->jump_verif = 1;
        }
        if (map->jump_verif != 0) {
            if (pos_p.y < 930) {
                sfSprite_move(game->ronin, pos), rect2_spt(window, &*game, &*c_anim);
                sfClock_restart(c_anim->clock); return (0);
            }
            map->jump_verif = 0;
        }
    }
    return (0);
}