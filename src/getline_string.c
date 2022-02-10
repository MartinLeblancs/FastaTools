/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../include/fastatools.h"
#include <stdlib.h>
#include <stdio.h>

void getline_file(struct fastatools *f)
{
    char *line = NULL;
    size_t len = 0;
    int y = 0;
    f->tab = malloc(sizeof(char *) * 100);
    for (y = 0; y <= 100; y++)
        f->tab[0] = NULL;
    y = 0;
    while (getline(&line, &len, stdin) != -1) {
        f->tab[y] = my_strduplicate(line);
        y++;
    }
    f->tab[y] = NULL;
}

char *put_all_in_string(struct fastatools *f)
{
    int x = 0;
    int y = 0;
    int i = 0;
    char *string = malloc(sizeof(char) * 10000);
    string[0] = '\0';

    for (; f->tab[y] != NULL; y++) {
        for (x = 0; f->tab[y][x] != '\0'; x++) {
            string[i] = f->tab[y][x];
            i++;
        }
    }
    string[i] = '\0';
    return (string);
}
