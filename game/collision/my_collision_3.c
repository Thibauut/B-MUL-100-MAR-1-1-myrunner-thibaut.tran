/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_collision_3.c
*/

#include "../../include/my.h"

int coll_rect_3(collide_t *c, my_list_t *obs_3, my_game_t *game)
{
    c->rect_p = sfSprite_getGlobalBounds(game->p);
    c->rect_p_2 = sfSprite_getGlobalBounds(game->p);
    c->rect_p_3 = sfSprite_getGlobalBounds(game->p);
    c->rect_obs_3 = sfSprite_getGlobalBounds(obs_3->obs);
    c->rect_obs_3_1 = sfSprite_getGlobalBounds(obs_3->obs);
    return (0);
}

int collision_3(m_l *list, g *game, sfrw *window, c *c, m *map, my_clock_t *clock)
{
    coll_rect_3(&*c, &*list, &*game);
    if (map->verif != 2) {
        ajust_rect_p(&c->rect_p, &c->rect_p_2);
        ajust_rect_obs_3(&c->rect_obs_3, &c->rect_obs_3_1);
        game->tmp = player_collide_3(window, &*c, &*game);
    }
    if (map->verif == 2) {
        ajust_rect_atk(&c->rect_p, &c->rect_p_2, &c->rect_p_3);
        player_collide_atk(window, &*c, &*list, &*map, &*clock);
    }
    return (0);
}

int player_collide_3(sfrw *window, collide_t *c, g *game)
{
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_3, NULL) == sfTrue)
        return (1);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_3, NULL) == sfTrue)
        return (1);
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_3_1, NULL) == sfTrue)
        return (1);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_3_1, NULL) == sfTrue)
        return (1);
    return (0);
}

int player_collide_atk(sfrw *window, c *c, m_l *list, m *map, my_clock_t *clock)
{
    sfvf pos = {-1000, -1000};
    if (sfFloatRect_intersects(&c->rect_p_3, &c->rect_obs_3, NULL) == sfTrue) {
        c->verif = 2;
        anim_obs_3_1(window, list, &*clock, &*map, &*c);
        if (c->verif == 0)
            sfSprite_setPosition(list->obs, pos);
    }
    if (sfFloatRect_intersects(&c->rect_p_3, &c->rect_obs_3_1, NULL) == sfTrue) {
        c->verif = 2;
        anim_obs_3_1(window, list, &*clock, &*map, &*c);
        if (c->verif == 0)
            sfSprite_setPosition(list->obs, pos);
    }
    return (0);
}