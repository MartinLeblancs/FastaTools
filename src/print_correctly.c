/*
** EPITECH PROJECT, 2020
** print_correctly.c
** File description:
** print_correctly.c
*/

#include "../include/fastatools.h"

void print_correctly(struct fastatools *f, int y, int x)
{
    if (f->tab[y][x] == 'A')
        my_putchar('T');
    if (f->tab[y][x] == 'T')
        my_putchar('A');
    check_c_g_n(f, y, x);
}

void check_c_g_n(struct fastatools *f, int y, int x)
{
    if (f->tab[y][x] == 'C')
        my_putchar('G');
    if (f->tab[y][x] == 'G')
        my_putchar('C');
    if (f->tab[y][x] == 'N')
        my_putchar('N');
}