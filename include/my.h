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

typedef struct my_menu_s {
    sfSprite *bg_menu;
    spt *title;
    spt *play;
    spt *exit;
    spt *option;
} my_menu_t;

typedef struct my_game_s {
    spt *bg_game;
    spt *bg_game_2;
    spt *bg_game_3;
    spt *ronin;
} my_game_t;

typedef struct my_obs_s {
    spt *obs_s;
    spt *obs_v;
    int i;
} my_obs_t;

typedef struct my_clock_s {
    sfClock *clock;
    sfTime time;
    float sec;
    int i;
    int j;
} my_clock_t;

typedef struct all_clock_s {
    my_clock_t c_bg;
    my_clock_t c_run;
    my_clock_t c_jump;
    my_clock_t c_move;
    my_clock_t c_jump2;
    my_clock_t c_obs;
} all_clock_t;

typedef struct my_var_s {
    int i;
    int j;
    int k;
    int l;
    int m;
    int n;
} my_var_t;

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

//load map
int open_my_file(char const *filepath);
int read_my_file(int fd, char *buffer, int size);
char *file_to_str(char const *filepath);
char **str_to_tab(char *file, int cols, int rows, my_map_t *map);
int my_show_word_array(char **tab);

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
void my_clock_anim(all_clock_t *clock);
void my_clock_restart(all_clock_t *clock);

//create
my_clock_t create_clock(void);
sfSprite* create_sprite(char* file, int x, int y, float scx, float scy);
sfRenderWindow *create_window(int x, int y, int i, char *my_title);
sfIntRect create_rect(int top, int left, int width, int height);

//my_h
int my_h();

//my_menu
int my_init_menu(char *av);
int my_menu(sfRenderWindow *window, char *av);
int display_menu(sfRenderWindow *window, my_menu_t menu);
int my_event_close(sfrw *window, sfEvent event, sfvi pos_m, sffr rect);
int my_event_play(sfrw *window, sfEvent event, sfvi pos_m, sffr play, char *av);
int but_menu(sfrw *window, my_menu_t menu, char *av);
spt *my_bg_anim(sfrw *window, spt *bg_menu, float seconds, my_var_t *var);
spt *rect_bg(sfRenderWindow *window, spt *bg_menu, my_var_t *var);
int my_anim_but(sffr rect, sfvi pos_m, sfvf size, sfvf sizeup, spt *menu);

//my_game
int init_game(sfrw *window, char *av);
void init_spt_game(my_game_t *game, my_obs_t *obs);
int my_game(sfrw *window, char *av);
int display_game(sfrw *window, my_game_t *game, my_obs_t *obs);
void bg_game_anim(sfrw *window, my_game_t *game, float sec, my_var_t *var);
void rect_bg_game(sfrw *window, my_game_t *game, my_var_t *var);
void rect_bg2_game(sfrw *window, my_game_t *game, my_var_t *var);
void rect_bg3_game(sfrw *window, my_game_t *game, my_var_t *var);
void rect_ronin(sfrw *window, my_game_t *game, my_var_t *var);
void bg_game(sfrw *window, my_game_t *game, my_var_t *var);
void spt_run(sfrw *window, my_game_t *game, float sec, my_var_t *var);

int but_game(sfrw *window, my_game_t *game, my_map_t *map, all_clock_t *clock);
void jump_player(sfrw *window, my_map_t *map, my_clock_t *clock);
void move_player(sfrw *window, my_map_t *map, my_clock_t *clock);
sfvi find_player(char **map);
void rect2_spt(sfrw *window, my_game_t *game, my_clock_t *c_anim);
int player_verif(sfEvent event, all_clock_t *clock, my_map_t *map);
int spt_jump(my_clock_t *c_anim, my_map_t *map, my_game_t *game, sfrw *window);

void check_map(sfrw *window, my_map_t *map, my_obs_t *obs, char *av);
void put_obs_1(sfrw *window, my_map_t *map, char str, my_obs_t *obs);
void add_obs(sfrw *window, my_obs_t *obs, sfvf pos, sfIntRect rect);
void move_obs(sfrw *window, my_obs_t *obs, my_clock_t *c_obs);

#endif