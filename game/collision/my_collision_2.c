/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_collision_2.c
*/

#include "../../include/my.h"

int coll_rect_2(collide_t *c, my_list_t *obs_2, my_game_t *game)
{
    c->rect_p = sfSprite_getGlobalBounds(game->p);
    c->rect_p_2 = sfSprite_getGlobalBounds(game->p);
    c->rect_obs_2 = sfSprite_getGlobalBounds(obs_2->obs);
    c->rect_obs_2_1= sfSprite_getGlobalBounds(obs_2->obs);
    return (0);
}

int collision_2(my_list_t *list, my_game_t *game, sfrw *window, collide_t *c)
{
    coll_rect_2(&*c, &*list, &*game);
    ajust_rect_p(&c->rect_p, &c->rect_p_2);
    ajust_rect_obs_2(&c->rect_obs_2, &c->rect_obs_2_1);
    game->tmp2 = player_collide_2(window, &*c);
    return (0);
}

int player_collide_2(sfrw *window, collide_t *c)
{
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_2, NULL) == sfTrue)
        return (1);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_2, NULL) == sfTrue)
        return (1);
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_2_1, NULL) == sfTrue)
        return (1);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_2_1, NULL) == sfTrue)
        return (1);
    return (0);
}