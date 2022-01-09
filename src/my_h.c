/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_h.c
*/

#include "../include/my.h"

int my_h(void)
{
    my_putstr("Finite runner created with CSFML.\n\n");
    my_putstr("USAGE\n   ./my_runner map.txt\n\nOPTIONS\n");
    my_putstr("   -i              launch the game in infinity mode.\n");
    my_putstr("   -h              print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr("   SPACE_KEY               jump.\n");
    my_putstr("   UP_KEY                  jump.\n");
    my_putstr("   A_KEY                   attack.\n");
    my_putstr("   Q_KEY                   quit.\n");
    my_putstr("   ECHAP_KEY               open option.\n");
    return (0);
}