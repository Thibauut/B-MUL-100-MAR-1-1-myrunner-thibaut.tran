/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_check_obs.c
*/

#include "../include/my.h"

void check_map(sfrw *window, my_map_t *map, my_obs_t *obs, char *av)
{
    map->map = file_to_str(av);
    my_putstr(map->map);
    map->x = 0, map->y = 1000, map->i = 0;
    while (map->map[map->i] != '\0') {
        map->x += 100;
        put_obs_1(window, &*map, map->map[map->i], &*obs);
        if (map->map[map->i] == '\n')
            map->x = 0;
        map->i += 1;
    }
}