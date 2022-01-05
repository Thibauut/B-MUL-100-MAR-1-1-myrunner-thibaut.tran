/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_collision.c
*/

#include "../include/my.h"

void init_rect(collide_t *c, my_list_t *obs_1, my_list_t *obs_2, my_game_t *game)
{
    c->rect_p = sfSprite_getGlobalBounds(game->p);
    c->rect_p_2 = sfSprite_getGlobalBounds(game->p);
    c->rect_obs_1 = sfSprite_getGlobalBounds(obs_1->obs);
    c->rect_obs_1_1 = sfSprite_getGlobalBounds(obs_1->obs);
    c->rect_obs_2 = sfSprite_getGlobalBounds(obs_2->obs);
    c->rect_obs_2_1= sfSprite_getGlobalBounds(obs_2->obs);
}

int collision(all_list_t *list, my_game_t *game, sfrw *window, collide_t *c)
{
    my_list_t *obs_1 = malloc(sizeof(my_list_t));
    obs_1 = list->list_1;
    my_list_t *obs_2 = malloc(sizeof(my_list_t));
    obs_2 = list->list_2;
    init_rect(&*c, &*obs_1, &*obs_2, &*game);
    ajust_rect_p(&c->rect_p, &c->rect_p_2);
    ajust_rect_obs_1(&c->rect_obs_1, &c->rect_obs_1_1);
    ajust_rect_obs_2(&c->rect_obs_2, &c->rect_obs_2_1);
    player_collide_1(window, &*c);
    player_collide_2(window, &*c);
    return (0);
}

void player_collide_1(sfrw *window, collide_t *c)
{
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_1, NULL) == sfTrue)
        sfRenderWindow_close(window);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_1, NULL) == sfTrue)
        sfRenderWindow_close(window);
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_1_1, NULL) == sfTrue)
        sfRenderWindow_close(window);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_1_1, NULL) == sfTrue)
        sfRenderWindow_close(window);
}

void player_collide_2(sfrw *window, collide_t *c)
{
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_2, NULL) == sfTrue)
        sfRenderWindow_close(window);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_2, NULL) == sfTrue)
        sfRenderWindow_close(window);
    if (sfFloatRect_intersects(&c->rect_p, &c->rect_obs_2_1, NULL) == sfTrue)
        sfRenderWindow_close(window);
    if (sfFloatRect_intersects(&c->rect_p_2, &c->rect_obs_2_1, NULL) == sfTrue)
        sfRenderWindow_close(window);
}