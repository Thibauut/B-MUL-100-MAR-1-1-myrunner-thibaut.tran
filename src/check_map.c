/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** check_map.c
*/

#include "../include/my.h"

sfvi find_player(char **map)
{
    int x = 0, y = 0;
    while (map[y][x] != 'X') {
        x += 1;
        if (x == 192) {
            y += 1;
            x = 0;
        }
    }
    sfvi pos_player = {x, y};
    return (pos_player);
}