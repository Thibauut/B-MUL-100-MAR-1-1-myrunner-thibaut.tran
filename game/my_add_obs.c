/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_add_obs.c
*/

#include "../include/my.h"

void add_obs(sfrw *window, my_obs_t *obs, sfvf pos, sfIntRect rect)
{
    obs->obs_s = create_sprite("res/sprite/spike.png", pos.x, pos.y, 3.5, 3.5);
    sfSprite_setTextureRect(obs->obs_s, rect);
}


void put_obs_1(sfrw *window, my_map_t *map, char str, my_obs_t *obs)
{
    if (str == '1') {
        sfvf pos = {map->x, map->y};
        add_obs(window, &*obs, pos, create_rect(0, 0, 16, 16));
        printf("\nx = %d y = %d\n", map->x, map->y);
        printf("\nici\n");
    }
}

void move_obs(sfrw *window, my_obs_t *obs, my_clock_t *c_obs)
{
    sfvf pos = {-5, 0}, pos_o = sfSprite_getPosition(obs->obs_s);
    if (c_obs->sec > 0.01) {
        if (pos_o.x != -100)
            sfSprite_move(obs->obs_s, pos);
        sfClock_restart(c_obs->clock);
    }
}