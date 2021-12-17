/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myhunter-thibaut.tran
** File description:
** my_func.c
*/

#include "../include/my.h"

void my_putchar(char c)
{
    write (1, &c, 1);
}

char *my_itoa(int nb)
{
    int size = 0;
    char *nb_in_str = NULL;
    int tmp = nb;
    if (tmp == 0)
        size = 1;
    while (tmp > 0) {
        tmp /= 10;
        size++;
    }
    nb_in_str = malloc(sizeof(char) * (size + 1));
    nb_in_str[size] = '\0';
    while (size--) {
        nb_in_str[size] = nb % 10  + '0';
        nb /= 10;
    }
    return (nb_in_str);
}

int my_strlen(char const *str)
{
    int i = 0;
    for (; str[i]; i += 1);
    return (i);
}

int my_getnbr(char const *str)
{
    int a = 0, nb = 0;
    int neg = 1;
    while (str[a] != '\0' && (str[a] < '0' || str[a] > '9')) {
        if (str[a] == '-')
            neg = neg * (-1);
        if (a == my_strlen(str))
            return (0);
        a++;
    }
    while (str[a] != '\0' && (str[a] >= '0' && str[a] <= '9')) {
        nb = nb * 10 + str[a] - 48;
        a++;
    }
    if (nb > 2147483647 || nb < -2147483647)
        return (0);
    return (nb * neg);
}

void my_putstr(char const *str)
{
    if (str == NULL)
        return;
    for (int i = 0; str[i]; i += 1)
        write(1, &str[i], 1);
}