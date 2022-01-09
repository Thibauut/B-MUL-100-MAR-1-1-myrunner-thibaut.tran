/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_display_game.c
*/

#include "../include/my.h"

int display_parallax(sfrw *w, g *game)
{
    sfRenderWindow_drawSprite(w, game->bg_game_1, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_2, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_3, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_4, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_5, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_6, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_7, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_8, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_9, NULL);
    sfRenderWindow_drawSprite(w, game->bg_game_10, NULL);
    return (0);
}

int display_obs(sfrw *w, g *game, a_l *list, all_c *clock, c *c, m *map, v_t *inf, music_t *music)
{
    my_list_t *obs_1 = malloc(sizeof(my_list_t));
    obs_1 = list->list_1;
    for (; obs_1 != NULL; obs_1 = obs_1->next) {
        anim_obs_1(w, obs_1, &clock->c_obs_1);
        move_obs(w, obs_1, &clock->c_obs);
        collision_1(obs_1, &*game, w, &*c);
        if (game->tmp3 == 1)
            print_lose(w, &*game, &*c, &*map, inf, &*music);
        sfRenderWindow_drawSprite(w, obs_1->obs, NULL);
    }
    return (0);
}

int display_obs2(sfrw *w, g *game, a_l *list, all_c *clock, c *c, m *map, v_t *inf, music_t *music)
{
    my_list_t *obs_2 = malloc(sizeof(my_list_t));
    obs_2 = list->list_2;
    for (; obs_2 != NULL; obs_2 = obs_2->next) {
        anim_obs_2(w, obs_2, &clock->c_obs_2);
        move_obs2(w, obs_2, &clock->c_obs);
        collision_2(obs_2, &*game, w, &*c);
        if (game->tmp2 == 1)
            print_lose(w, &*game, &*c, &*map, inf, &*music);
        sfRenderWindow_drawSprite(w, obs_2->obs, NULL);
    }
    return (0);
}

int display_obs3(sfrw *w, g *game, a_l *list, all_c *clock, c *c, m *map, v_t *inf, music_t *music)
{
    my_list_t *obs_3 = malloc(sizeof(my_list_t));
    obs_3 = list->list_3;
    for (; obs_3 != NULL; obs_3 = obs_3->next) {
        anim_obs_3(w, obs_3, &clock->c_obs_3, &*map, &*c);
        move_obs(w, obs_3, &clock->c_obs);
        collision_3(obs_3, &*game, w, &*c, &*map, &clock->c_obs_3_1);
        if (game->tmp == 1)
            print_lose(w, &*game, &*c, &*map, inf, &*music);
        sfRenderWindow_drawSprite(w, obs_3->obs, NULL);
    }
    return (0);
}