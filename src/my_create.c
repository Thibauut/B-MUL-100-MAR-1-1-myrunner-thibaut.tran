/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** my_create.c
*/

#include "../include/my.h"

sfRenderWindow *create_window(int x, int y, int i, char *my_title)
{
    sfVideoMode mode = {x, y, i};
    return (sfRenderWindow_create(mode, my_title, sfDefaultStyle, NULL));
}

sfSprite *create_sprite(char* file, int x, int y, float scx, float scy)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(file, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfVector2f scale = {scx, scy};
    sfSprite_setScale(sprite, scale);
    sfVector2f pos = {x, y};
    sfSprite_setPosition(sprite, pos);
    return (sprite);
}

my_clock_t create_clock(void)
{
    my_clock_t my_clock;
    my_clock.clock = sfcc();
    my_clock.seconds = 0;
    return (my_clock);
}

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect;
    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

sfText* create_text(char *str, int size, sfColor color, float x, float y, sfColor color2)
{
    sfText* text;
    sfFont* font;
    float outline = 3;
    sfVector2f pos = {x, y}, scale = {1, 1};
    font = sfFont_createFromFile("res/font/galaxy.ttf");
    text = sfText_create();
    sfText_setString(text, str);
    sfText_setScale(text, scale);
    sfText_setFont(text, font);
    sfText_setColor(text, color);
    sfText_setCharacterSize(text, size);
    sfText_setOutlineColor(text, color2);
    sfText_setOutlineThickness(text, outline);
    sfText_setPosition(text, pos);
    return (text);
}