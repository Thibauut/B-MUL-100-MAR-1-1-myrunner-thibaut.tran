/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_put_obs.c
*/

#include "../include/my.h"

int put_obs_1(sfrw *window, my_map_t *map, char str, all_list_t *list)
{
    if (str == '1') {
        sfvf pos = {map->x, map->y};
        add_obs_1(window, &*list, pos, create_rect(0, 0, 36, 30));
    }
    return (0);
}

int put_obs_2(sfrw *window, my_map_t *map, char str, all_list_t *list)
{
    if (str == '2') {
        sfvf pos = {map->x, map->y};
        add_obs_2(window, &*list, pos, create_rect(0, 0, 32, 32));
    }
    return (0);
}

int put_obs_3(sfrw *window, my_map_t *map, char str, all_list_t *list)
{
    if (str == '3') {
        sfvf pos = {map->x, map->y};
        add_obs_3(window, &*list, pos, create_rect(0, 0, 32, 32));
    }
    return (0);
}