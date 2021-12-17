/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_runner.c
*/

#include "include/my.h"

int main (int ac, char **av)
{
    if (ac > 2)
        return (84);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0')
        my_h();
    else
    my_init_menu(av[1]);
}