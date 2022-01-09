/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_collision.c
*/

#include "../../include/my.h"

int coll_rect_1(collide_t *c, my_list_t *obs_1, my_game_t *game)
{
    c->rect_p = sfSprite_getGlobalBounds(game->p);
    c->rect_p_2 = sfSprite_getGlobalBounds(game->p);
    c->rect_obs_1 = sfSprite_getGlobalBounds(obs_1->obs);
    c->rect_obs_1_1 = sfSprite_getGlobalBounds(obs_1->obs);
    return (0);
}

int collision_1(my_list_t *list, my_game_t *game, sfrw *window, collide_t *c)
{
    coll_rect_1(&*c, &*list, &*game);
    ajust_rect_p(&c->rect_p, &c->rect_p_2);
    ajust_rect_obs_1(&c->rect_obs_1, &c->rect_obs_1_1);
    game->tmp3 = player_collide_1(window, &*c);
    return (0);
}

int player_collide_1(sfrw *window, collide_t *c)
{
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_1, NULL) == sfTrue)
        return (1);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_1, NULL) == sfTrue)
        return (1);
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_1_1, NULL) == sfTrue)
        return (1);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_1_1, NULL) == sfTrue)
        return (1);
    return (0);
}