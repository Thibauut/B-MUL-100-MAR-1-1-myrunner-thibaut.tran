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

spt *rect2_ronin(sfrw *window, my_game_t game, int i)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0 + i;
    rect.width = 64;
    rect.height = 64;
    sfSprite_setTextureRect(game.ronin, rect);
    return (game.ronin);
}

void anim_jump(my_clock_t *c_anim, my_map_t map, my_game_t game, sfrw *window)
{
    c_anim->time = sfClock_getElapsedTime(c_anim->clock);
    c_anim->sec = c_anim->time.microseconds / 1000000.0;
    if (c_anim->sec > 0.1) {
            game.ronin = rect2_ronin(window, game, c_anim->i);
            c_anim->i += 64;
            if (c_anim->i >= 960) {
                c_anim->i = 0;
                map.jump = False;
            }
        sfClock_restart(c_anim->clock);
    }
}

char **move_sprite(my_map_t map, my_game_t game)
{
    map.pos.x = 0;
    map.pos = find_player(map.map);
    my_show_word_array(map.map);
    map.map[map.pos.y][map.pos.x] = '.';
    map.map[map.pos.y - 15][map.pos.x] = 'X';
    sfvf pos_tmp = {map.pos.x, 830 - ((map.pos.y - 121) * (-10))};
    return (map.map);
}

int my_button_game(sfrw *window, my_game_t game, my_map_t map)
{
    sfEvent event;
    sfVector2i pos_mouse;
    sfTexture *jump = sfTexture_createFromFile("res/sprite/ronin_jump.png", NULL);
    my_clock_t c_anim = {sfClock_create(), 0, 0};
    while (sfRenderWindow_pollEvent(window, &event)) {
        pos_mouse = sfMouse_getPositionRenderWindow(window);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp) {
            sfSprite_setTexture(game.ronin, jump, sfFalse);
            map.map = move_sprite(map, game);
            c_anim.i = 0;
            map.jump = True;
            my_show_word_array(map.map);
        }
    }
    if (map.jump == True)
        anim_jump(&c_anim, map, game, window);
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

int my_game(sfrw *window, char *av)
{
    my_clock_t c_bg = {sfClock_create(), 0, 0}, c1 = {sfClock_create(), 0, 0};
    my_var_t *var = malloc(sizeof(my_var_t));
    var->i = 0, var->j = 0, var->k = 0, var->m = 0;
    my_game_t game = my_init_spt_game(game);
    my_map_t map;
    map.map = str_to_tab(av, 192, 108);
    while (sfRenderWindow_isOpen(window)) {
        c_bg.time = sfcget(c_bg.clock), c_bg.sec = c_bg.time.m_sec / 1000000.0;
        c1.time = sfcget(c1.clock), c1.sec = c1.time.m_sec / 1000000.0;
        my_button_game(window, game, map);
        game = bg_game_anim(window, game, c_bg.sec, var);
        if (map.jump != True) game = ronin_anim(window, game, c1.sec, var);
        if (c_bg.sec > 0.01) sfClock_restart(c_bg.clock);
        if (c1.sec > 0.07) sfClock_restart(c1.clock);
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