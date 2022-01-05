/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_func_link_list.c
*/

#include "../include/my.h"

all_list_t init_list(void)
{
    all_list_t list;
    list.list_1 = NULL;
    list.list_2 = NULL;
    list.list_3 = NULL;
    list.list_4 = NULL;
    return (list);
}

my_list_t *add_element(my_list_t *list, spt *obs, int pos)
{
    my_list_t *prev = list;
    my_list_t *curr = list;
    my_list_t *cell = create_cell(obs);
    if (list == NULL)
        return (cell);
    if (pos == 0) {
        cell->next = list;
        return (cell);
    }
    for (int i = 0; i < pos; i += 1) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = cell;
    cell->next = curr;
    return (list);
}

my_list_t *create_cell(spt *obs)
{
    my_list_t *cell = malloc(sizeof(my_list_t));
    if (cell == NULL)
        return (NULL);
    cell->obs = obs;
    cell->next = NULL;
    return (cell);
}

spt *get_element(my_list_t *list, int pos)
{
    for (int i = 0; i < pos; i += 1)
        list = list->next;
    return (list->obs);
}