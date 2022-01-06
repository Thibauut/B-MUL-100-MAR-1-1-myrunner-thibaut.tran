/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my.h
*/

#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Config.h>
#include <SFML/Network.h>
#include <SFML/GPUPreference.h>
#include <SFML/OpenGL.h>
#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>
#define sfcc sfClock_create
#define sfkp sfEvtKeyPressed
#define sfec sfEvtClosed
#define spt sfSprite
#define sfrw sfRenderWindow
#define sfvi sfVector2i
#define sfvf sfVector2f
#define sffr sfFloatRect
#define sfcget sfClock_getElapsedTime
#define m_sec microseconds
#define sec seconds
#define sfkey sfKeyboard_isKeyPressed
#define sfir sfIntRect
#define sffr sfFloatRect
#define sfsgp sfSprite_getPosition
#define sfsm sfSprite_move
#define all_c all_clock_t
#define c collide_t

typedef struct my_list_s {
    sfSprite *obs;
    struct my_list_s *next;
    struct my_list_s *prev;
} my_list_t;

typedef struct all_list_s {
    my_list_t *list_1;
    my_list_t *list_2;
    my_list_t *list_3;
    my_list_t *list_4;
} all_list_t;

typedef struct my_menu_s {
    sfSprite *bg_menu;
    spt *title;
    spt *play;
    spt *exit;
    spt *option;
    int i;
    int j;
    int k;
} my_menu_t;

typedef struct collide_s {
    sfFloatRect rect_p;
    sfFloatRect rect_p_2;
    sfFloatRect rect_obs_1;
    sfFloatRect rect_obs_1_1;
    sfFloatRect rect_obs_2;
    sfFloatRect rect_obs_2_1;
} collide_t;

typedef struct my_game_s {
    spt *bg_game;
    spt *bg_game_2;
    spt *bg_game_3;
    spt *p;
    int i;
} my_game_t;

typedef struct my_clock_s {
    sfClock *clock;
    sfTime time;
    float sec;
    int i;
    int j;
    int k;
} my_clock_t;

typedef struct all_clock_s {
    my_clock_t c_bg;
    my_clock_t c_run;
    my_clock_t c_jump;
    my_clock_t c_move;
    my_clock_t c_jump2;
    my_clock_t c_obs;
    my_clock_t c_obs_1;
    my_clock_t c_obs_2;
    my_clock_t c_obs_3;
    my_clock_t c_atk;
} all_clock_t;

typedef struct my_map_s {
    char *map;
    sfvi pos_move;
    sfvi pos_jump;
    sfvi pos_obs;
    int verif;
    int jump_verif;
    sfvi pos_tmp;
    int x;
    int y;
    int i;
} my_map_t;

#ifndef MY_H_
#define MY_H_

all_list_t init_list(void);
my_list_t *create_cell(sfSprite *obs);
my_list_t *free_list(my_list_t *list);
my_list_t *add_element(my_list_t *list, sfSprite *obs, int pos);
spt *get_element(my_list_t *list, int pos);
int open_my_file(char const *filepath);
int read_my_file(int fd, char *buffer, int size);
char *file_to_str(char const *filepath);

//lib
void my_putchar(char c);
char *my_itoa(int nb);
void my_putstr(char const *str);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int set_random(int max, int min);
void my_put_nbr(int nb);

//clock
all_clock_t init_clock(void);
int my_clock_anim(all_clock_t *clock);

//create
my_clock_t create_clock(void);
sfSprite* create_sprite(char* file, int x, int y, float scx, float scy);
sfRenderWindow *create_window(int x, int y, int i, char *my_title);
sfIntRect create_rect(int top, int left, int width, int height);

//my_h
int my_h();
//my_menu
int init_sprite_menu(my_menu_t *menu);
int my_init_menu(char *av);
int my_menu(sfRenderWindow *window, char *av);
int display_menu(sfRenderWindow *window, my_menu_t menu);
int my_event_close(sfrw *window, sfEvent event, sfvi pos_m, sffr rect);
int my_event_play(sfrw *window, sfEvent event, sfvi pos_m, sffr play, char *av);
int but_menu(sfrw *window, my_menu_t menu, char *av);
int my_bg_anim(sfrw *window, my_menu_t *menu, my_clock_t *c_bg);
int rect_bg(sfRenderWindow *window, my_menu_t *menu);
int my_anim_but(sffr rect, sfvi pos_m, sfvf size, sfvf sizeup, spt *menu);

//my_game
int init_variable(all_clock_t *clock, my_map_t *map, my_game_t *game);
int init_menu_variable(my_menu_t *menu);
int init_game(sfrw *window, char *av);
int init_spt_game(my_game_t *game);
all_list_t init_list(void);
int my_game(sfrw *window, char *av);
int display_game(sfrw *w, my_game_t *game, all_list_t *list, all_clock_t *clock, collide_t *c);
int display_obs(sfrw *w, my_game_t *game, all_list_t *list, all_clock_t *clock, collide_t *c);
int bg_game_anim(sfrw *window, my_game_t *game, my_clock_t *c_bg);
int rect_bg_game(sfrw *window, my_game_t *game, my_clock_t *c_bg);
int rect_bg2_game(sfrw *window, my_game_t *game, my_clock_t *c_bg);
int rect_bg3_game(sfrw *window, my_game_t *game, my_clock_t *c_bg);
int rect_spt(sfrw *window, my_game_t *game, my_clock_t *c_run);
int bg_game(sfrw *window, my_game_t *game, my_clock_t *c_bg);
int spt_run(sfrw *window, my_game_t *game, my_clock_t *c_run);

int but_game(sfrw *window, my_game_t *game, my_map_t *map, all_clock_t *clock);
int jump_player(sfrw *window, my_map_t *map, my_clock_t *clock);
int move_player(sfrw *window, my_map_t *map, my_clock_t *clock);
sfvi find_player(char **map);
int rect2_spt(sfrw *window, my_game_t *game, my_clock_t *c_anim);
int rect3_spt(sfrw *window, my_game_t *game, my_clock_t *c_anim);
int player_verif(sfEvent *ev, all_clock_t *clock, my_map_t *map);
int spt_jump(my_clock_t *c_jump, my_map_t *map, my_game_t *game, sfrw *window);
int spt_atk(my_clock_t *c_atk, my_map_t *map, my_game_t *game, sfrw *window);
int check_obs(sfrw *window, my_map_t *map, all_list_t *list, char *av);
int move_obs(sfrw *window, my_list_t *list, my_clock_t *c_obs);
int move_obs2(sfrw *window, my_list_t *list, my_clock_t *c_obs);
int move_obs3(sfrw *window, my_list_t *list, my_clock_t *c_obs);
//obs1
int put_obs_1(sfrw *window, my_map_t *map, char str, all_list_t *list);
int add_obs_1(sfrw *window, all_list_t *list, sfvf pos, sfIntRect rect);
int anim_obs_1(sfrw *window, my_list_t *list, my_clock_t *c_obs_1);
int rect_obs_1(sfrw *window, my_list_t *list, my_clock_t *c_obs_1);
//obs2
int put_obs_2(sfrw *window, my_map_t *map, char str, all_list_t *list);
int add_obs_2(sfrw *window, all_list_t *list, sfvf pos, sfIntRect rect);
int anim_obs_2(sfrw *window, my_list_t *list, my_clock_t *c_obs_2);
int rect_obs_2(sfrw *window, my_list_t *list, my_clock_t *c_obs_2);

int add_obs_3(sfrw *window, all_list_t *list, sfvf pos, sfIntRect rect);
int put_obs_3(sfrw *window, my_map_t *map, char str, all_list_t *list);
int anim_obs_3(sfrw *window, my_list_t *list, my_clock_t *c_obs_3);
//collision
int collision_1(my_list_t *list, my_game_t *game, sfrw *window, collide_t *c);
int collision_2(my_list_t *list, my_game_t *game, sfrw *window, collide_t *c);
int ajust_rect_p(sfFloatRect *rect_p, sfFloatRect *rect_p_2);
int ajust_rect_obs_1(sfFloatRect *rect_obs_1, sfFloatRect *rect_obs_1_1);
int ajust_rect_obs_2(sfFloatRect *rect_obs_2, sfFloatRect *rect_obs_2_1);
int player_collide_1(sfrw *window, collide_t *c);
int player_collide_2(sfrw *window, collide_t *c);
int coll_rect_1(collide_t *c, my_list_t *obs_1, my_game_t *game);
int coll_rect_2(collide_t *c, my_list_t *obs_2, my_game_t *game);

int my_clock_anim2(all_clock_t *clock);

#endif