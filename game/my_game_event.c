/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game_event.c
*/

#include "../include/my.h"



int player_verif(sfEvent event, all_clock_t *clock, my_map_t *map)
{
    if (sfkey(sfKeyUp) || sfkey(sfKeySpace) && map->verif == 0) {
        clock->c_jump.i = 0;
        map->verif = 1;
        map->jump_verif = 0;
    }
    return (map->verif);
}