/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_game.c
*/

#include "../include/my.h"

int my_init_game(sfrw *window, char *av)
{
    sfRenderWindow_setFramerateLimit(window, 60);
    my_game(window, av);
    return (0);
}

my_game_t my_init_spt_game(my_game_t game)
{
    game.bg_game = create_sprite("res/game/bg_game.png", 0, 0, 1, 1);
    game.bg_game_2 = create_sprite("res/game/bg_game_2.png", 0, -100, 1, 1);
    game.bg_game_3 = create_sprite("res/game/bg_game_3.png", 0, 60, 1, 1);
    game.ronin = create_sprite("res/sprite/ronin_spt.png", 0, 830, 5, 5);
    return (game);
}

sfvi move_sprite(my_map_t *map, my_game_t game)
{
    map->pos.x = 0, map->pos.y = 0;
    map->pos = find_player(map->map);
    map->map[map->pos.y][map->pos.x] = '.';
    map->map[map->pos.y - 10][map->pos.x] = 'X';
    sfvi pos_tmp = {map->pos.x, 830 - ((map->pos.y - 116) * (-10))};
    return (pos_tmp);
}

int my_button_game(sfrw *window, my_game_t game, my_map_t *map, my_clock_t *c_anim)
{
    sfEvent event;
    sfVector2i pos_mouse;
    while (sfRenderWindow_pollEvent(window, &event)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        if (event.type == sfec || (event.type == sfkp && event.key.code == sfKeyQ))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
            map->pos_tmp = move_sprite(map, game);
            c_anim->i = 0;
            map->verif = 1;
        }
    }
    if (map->verif == 1) ronin_jump(&*c_anim, &*map, game, window);
    return (0);
}


int my_game(sfrw *window, char *av)
{
    all_clock_t clock = fill_clock();
    my_var_t *var = malloc(sizeof(my_var_t));
    var->i = 0, var->j = 0, var->k = 0, var->m = 0;
    my_game_t game = my_init_spt_game(game);
    my_map_t map;
    map.map = str_to_tab(av, 192, 108), map.verif = 0;
    while (sfRenderWindow_isOpen(window)) {
        my_clock_anim(&clock);
        game = bg_game_anim(window, game, clock.c_bg.sec, var);
        if (map.verif == 0) game = ronin_run(window, game, clock.c_run.sec, var);
        my_button_game(window, game, &map, &clock.c_jump);
        my_clock_restart(&clock);
        display_game(window, game);
    }
    return (0);
}

int display_game(sfRenderWindow *window, my_game_t game)
{
    sfRenderWindow_drawSprite(window, game.bg_game, NULL);
    sfRenderWindow_drawSprite(window, game.bg_game_2, NULL);
    sfRenderWindow_drawSprite(window, game.bg_game_3, NULL);
    sfRenderWindow_drawSprite(window, game.ronin, NULL);
    sfRenderWindow_display(window);
    return (0);
}