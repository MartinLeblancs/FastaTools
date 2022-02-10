/*
** EPITECH PROJECT, 2020
** display.c
** File description:
** display.c
*/

#include "../include/fastatools.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(struct fastatools *f)
{
    for (int z = 0; f->tab[z] != NULL; z++) {
        my_putstr(f->tab[z]);
    }
    my_putchar('\n');
}

void display_4_1(void)
{
    my_putstr("A\n");
    my_putstr("C\n");
    my_putstr("G\n");
    my_putstr("T\n");
}

void print_second_tab_cod_sqc(struct fastatools *f)
{
    int i = 0;

    while (f->second_tab[i] != NULL) {
        if (my_strlen(f->second_tab[i]) % 3 == 0) {
            my_putstr(f->second_tab[i]);
            my_putchar('\n');
        }
            i++;
    }
}

void print_second_tab(struct fastatools *f)
{
    int i = 0;

    while (f->second_tab[i] != NULL) {
        if (i != 0 && my_strcmp(f->second_tab[i], f->second_tab[i - 1]) != 1) {
            my_putstr(f->second_tab[i]);
            my_putchar('\n');
        }
        i++;
    }
}