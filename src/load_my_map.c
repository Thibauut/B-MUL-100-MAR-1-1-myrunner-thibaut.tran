/*
** EPITECH PROJECT, 2021
** B-CPE-110-MAR-1-1-BSQ-thibaut.tran
** File description:
** load_my_tab.c
*/

#include "../include/my.h"

int my_show_word_array(char **tab)
{
    int a = 0;
    while (tab[a] != NULL) {
        my_putstr(tab[a]);
        my_putstr("\n");
        a++;
    }
    return (0);
}

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
    int k = 0;
    struct stat buf;
    stat(filepath, &buf);
    int size = buf.st_size;
    char *buffer = malloc(sizeof(char) * size);
    int fd = open_my_file(filepath);
    read_my_file(fd, buffer, size);
    close(fd);
    return (buffer);
}

char **str_to_tab(char *file, int x, int y)
{
    int i = 0, j = 0, k = 0;
    char *tab_str = file_to_str(file);
    char **tab = malloc(sizeof(char *) * (y + 1));
    while (i < y) {
        tab[i] = malloc(sizeof(char) * (x + 1));
        while (j < x) {
            tab[i][j] = tab_str[k];
            j += 1, k += 1;
        }
        j = 0, k += 1, i += 1;
    }
    return (tab);
}