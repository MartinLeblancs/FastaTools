/*
** EPITECH PROJECT, 2020
** reorganize_struct
** File description:
** reorganize_struct
*/

#include "../include/fastatools.h"
#include <stdlib.h>
#include <stdio.h>

void initialized_utils(struct utils *u)
{
    u->i = 0;
    u->x = 0;
    u->y = 0;
}

char **put_in_maj(struct fastatools *f, char *string, struct utils *u)
{
    if (string[u->i] == 'a' || string[u->i] == 't' || string[u->i] == 'g'
        || string[u->i] == 'c' || string[u->i] == 'n')
        f->tab[u->y][u->x] = string[u->i] - 32;
    else if (check_char(string, u->i) == 2)
        f->tab[u->y][u->x] = string[u->i];
    return (f->tab);
}

void reorganize_string(char *string, struct fastatools *f)
{
    struct utils *u = malloc(sizeof(struct utils));
    initialized_utils(u);

    for (u->i = 0; string[u->i] != '\0';) {
        if (string[u->i] == '>') {
            for (u->x = 0; string[u->i] != '\n'; u->x++, u->i++)
                f->tab[u->y][u->x] = string[u->i];
            f->tab[u->y][u->x] = '\n';
            f->tab[u->y][u->x + 1] = '\0';
        }
        for (u->x = 0, u->y++, u->i++; string[u->i] != '>'
        && string[u->i] != '\0'; u->i++, u->x++) {
            u->i = remove_not_correct_char(string, u->i);
            u->i = remove_char(string, u->i);
            put_in_maj(f, string, u);
        }
        u->y++;
    }
    free(u);
}