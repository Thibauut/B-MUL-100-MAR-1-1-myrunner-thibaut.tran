/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myhunter-thibaut.tran
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

typedef enum
{
    True,
    False,
}bool;

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

typedef struct my_clock_s {
    sfClock *clock;
    sfTime time;
    float sec;
    int i;
    int j;
} my_clock_t;

typedef struct my_var_s {
    int i;
    int j;
    int k;
    int l;
    int m;
} my_var_t;

typedef struct my_map_s {
    char **map;
    sfvi pos;
    bool jump;
    int verif;
    sfvi pos_tmp;
} my_map_t;

#ifndef MY_H_
#define MY_H_

//load map
int open_my_file(char const *filepath);
int read_my_file(int fd, char *buffer, int size);
char *file_to_str(char const *filepath);
char **str_to_tab(char *file, int cols, int rows);
int my_show_word_array(char **tab);
//lib
void my_putchar(char c);
char *my_itoa(int nb);
void my_putstr(char const *str);
int my_getnbr(char const *str);
int my_strlen(char const *str);
int set_random(int max, int min);
void my_put_nbr(int nb);

//window
sfSprite* create_sprite(char* file, int x, int y, float scx, float scy);
sfRenderWindow *create_window(int x, int y, int i, char *my_title);

//my_h
int my_h();

//my_menu
int my_init_menu(char *av);
int my_menu(sfRenderWindow *window, char *av);
int display_menu(sfRenderWindow *window, my_menu_t menu);
int my_event_close(sfrw *window, sfEvent event, sfvi pos_m, sffr rect);
int my_event_play(sfrw *window, sfEvent event, sfvi pos_m, sffr play, char *av);
int my_button(sfrw *window, my_menu_t menu, char *av);
spt *my_bg_anim(sfrw *window, spt *bg_menu, float seconds, my_var_t *var);
spt *rect_bg(sfRenderWindow *window, spt *bg_menu, my_var_t *var);
int my_anim_but(sffr rect, sfvi pos_m, sfvf size, sfvf sizeup, spt *menu);

//my_game
int my_init_game(sfrw *window, char *av);
my_game_t my_init_spt_game(my_game_t game);
int my_game(sfrw *window, char *av);
int display_game(sfRenderWindow *window, my_game_t game);
my_game_t bg_game_anim(sfrw *window, my_game_t game, float sec, my_var_t *var);
spt *rect_bg_game(sfRenderWindow *window, my_game_t game, my_var_t *var);
spt *rect_bg2_game(sfrw *window, my_game_t game, my_var_t *var);
spt *rect_bg3_game(sfrw *window, my_game_t game, my_var_t *var);
spt *rect_ronin(sfrw *window, my_game_t game, my_var_t *var);
my_game_t my_bg_game(sfrw *window, my_game_t game, my_var_t *var);
my_game_t my_ronin_game(sfrw *window, my_game_t game, my_var_t *var);
my_game_t ronin_anim(sfrw *window, my_game_t game, float sec, my_var_t *var);

int my_button_game(sfrw *window, my_game_t game, my_map_t *map, my_clock_t *c_anim);

sfvi move_sprite(my_map_t *map, my_game_t game);
sfvi find_player(char **map);

spt *rect2_ronin(sfrw *window, my_game_t game, my_clock_t *c_anim);
void ronin_jump(my_clock_t *c_anim, my_map_t *map, my_game_t game, sfrw *window);

#endif