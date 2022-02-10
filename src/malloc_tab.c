/*
** EPITECH PROJECT, 2020
** malloc_tab
** File description:
** malloc_tab
*/

#include "../include/fastatools.h"
#include <stdlib.h>

int go_after_seq(char *string, int i)
{
    if (string[i] == '>') {
        while (string[i] != '\n') {
            i++;
        }
    }
    return (i);
}

void malloc_tab(char *string, struct fastatools *f)
{
    int i = 0;
    int count_malloc = 0;

    while (string[i] != '\0') {
        i = go_after_seq(string, i);
        count_malloc++;
        while (string[i] != '>' && string[i] != '\0') {
            i++;
        }
        count_malloc++;
    }
    i = 0;
    f->tab = malloc(sizeof(char *) * count_malloc + 1);
}

void malloc_tab_lines(char *string, struct fastatools *f) {
    int i = 0;
    int y = 0;
    int count_malloc = 0;

    for (; string[i] != '\0'; y++) {
        count_malloc = 0;
        if (string[i] == '>') {
            for (; string[i] != '\n'; count_malloc++, i++) {
            }
            count_malloc++;
        }
        f->tab[y] = malloc(sizeof(char *) * count_malloc);
        f->tab[y][0] = '\0';
        for (y++; string[i] != '>' && string[i] != '\0'; i++, count_malloc++) {
        }
        f->tab[y] = malloc(sizeof(char *) * count_malloc);
        f->tab[y][0] = '\0';
    }
    f->nb_lines_malloc = y + 1;
}