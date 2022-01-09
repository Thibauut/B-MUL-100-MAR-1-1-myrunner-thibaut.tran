/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_runner.c
*/

#include "include/my.h"

int main (int ac, char **av)
{
    verif_inf_t *inf = malloc(sizeof(verif_inf_t));
    inf->i = 0;
    if (ac > 2)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        my_h();
    else if (ac == 2 && av[1][0] == '-' && av[1][1] == 'i' && av[1][2] == '\0')
        inf->i = 1, my_init_menu("map_inf.txt", inf);
    else
        inf->i = 0, my_init_menu(av[1], inf);
}