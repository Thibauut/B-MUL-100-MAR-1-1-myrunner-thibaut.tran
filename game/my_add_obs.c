/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_add_obs.c
*/

#include "../include/my.h"

int add_obs_1(sfrw *window, all_list_t *list, sfvf pos, sfIntRect rect)
{
    spt *obs = create_sprite("res/sprite/obs_1.png", pos.x, pos.y, 2.5, 2.5);
    list->list_1 = add_element(list->list_1, obs, 0);
    sfSprite_setTextureRect(list->list_1->obs, rect);
    return (0);
}

int add_obs_2(sfrw *window, all_list_t *list, sfvf pos, sfIntRect rect)
{
    spt *obs = create_sprite("res/sprite/obs_2.png", pos.x, pos.y, 2.7, 2.7);
    list->list_2 = add_element(list->list_2, obs, 0);
    sfSprite_setTextureRect(list->list_2->obs, rect);
    return (0);
}

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

int check_obs(sfrw *window, my_map_t *map, all_list_t *list, char *av)
{
    map->map = file_to_str(av);
    my_putstr(map->map);
    map->x = 0, map->y = 830, map->i = 0;
    while (map->map[map->i] != '\0') {
        map->x += 200;
        put_obs_1(window, &*map, map->map[map->i], &*list);
        put_obs_2(window, &*map, map->map[map->i], &*list);
        if (map->map[map->i] == '\n')
            map->x = 0, map->y += 125;
        map->i += 1;
    }
    return (0);
}