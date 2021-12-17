/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_sprite.c
*/

#include "../include/my.h"

sfRenderWindow *create_window(int x, int y, int i, char *my_title)
{
    sfVideoMode mode = {x, y, i};
    return (sfRenderWindow_create(mode, my_title, sfDefaultStyle, NULL));
}

sfSprite* create_sprite(char* file, int x, int y, float scx, float scy)
{
    sfSprite* sprite = sfSprite_create();
    sfTexture* texture = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfVector2f scale = {scx, scy};
    sfSprite_setScale(sprite, scale);
    sfVector2f pos = {x, y};
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}