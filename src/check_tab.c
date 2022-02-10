/*
** EPITECH PROJECT, 2020
** check_tab.c
** File description:
** check_tab.c
*/

#include "../include/fastatools.h"
#include <unistd.h>
#include <stdlib.h>

void error(void)
{
    write(2, "Error in file\n", 15);
    exit (84);
}

void check_error_in_tab(struct fastatools *f, int y)
{
    if (y % 2 != 0) {
        if (f->tab[y][0] == '\0'
            || f->tab[y][0] == '\n' || f->tab[y][0] == ' ')
            error();
    }
}

void check_tab(struct fastatools *f)
{
    int y = 0;
    int x = 0;
    int count = 0;

    if (f->tab[0][0] == '\0' || f->tab[1][0] == '\0')
        error();
    for (y = 0; f->tab[y] != NULL; y++) {
        for (x = 0; f->tab[y][x] != '\0'; x++) {
            if (f->tab[y][x] == '>')
                count++;
            check_error_in_tab(f, y);
        }
    }
    if (count == 0)
        error();
}