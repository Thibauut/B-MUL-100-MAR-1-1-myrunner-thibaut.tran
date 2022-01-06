/*
** EPITECH PROJECT, 2021
** B-MUL-100-MAR-1-1-myrunner-thibaut.tran
** File description:
** load_my_map.c
*/

#include "../include/my.h"

int open_my_file(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    if (fd < 0)
        return (84);
    return (fd);
}

int read_my_file(int fd, char *buffer, int size)
{
    read(fd, buffer, size);
    return (0);
}

char *file_to_str(char const *filepath)
{
    int size = 241;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open_my_file(filepath);
    read_my_file(fd, buffer, size);
    close(fd);
    return (buffer);
}