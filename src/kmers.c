/*
** EPITECH PROJECT, 2020
** kmers
** File description:
** kmers
*/

#include "../include/fastatools.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int execute_4(struct fastatools *f)
{
    int y = 0;
    int x = 0;
    int i = 0;
    int y2 = 0;

    for (x = 0 ; f->tab[y] != NULL; y++) {
        i = 0;
        if (y != 0 && y % 2 != 0) {
            for (; i < ((my_strlen_kmers(f->tab[y])) - f->k_mers) + 1; y2++) {
                x = i;
                for (int x2 = 0; x < f->k_mers + i; x++, x2++)
                    f->second_tab[y2][x2] = f->tab[y][x];
                i++;
            }
        }
    }
    f->second_tab[y2 + 1] = NULL;
    return (y2);
}

void malloc_kmers_tab(struct fastatools *f, int y)
{
    int i = 0;

    f->second_tab = malloc(sizeof(char **) * (y + 1));
    while (i <= y) {
        f->second_tab[i] = malloc(sizeof(char) * (f->opt_4 + 1000));
        i++;
    }
    f->nb_line_malloc_second = y;
}

void test_for_malloc_kmers(struct fastatools *f)
{
    int y = 0;
    int x = 0;
    int i = 0;
    int y2 = 0;

    for (x = 0 ; f->tab[y] != NULL; y++) {
        i = 0;
        x = 0;
        if (y != 0 && y % 2 != 0) {
            for (; i <= ((my_strlen_kmers(f->tab[y])) - f->k_mers); y2++) {
                x = i;
                for (int x2 = 0; x < f->k_mers + i; x++, x2++) {
                }
                    i++;
            }
        }
    }
    malloc_kmers_tab(f, y2);
}

int compare(const void *a, const void *b)
{
    const char **ia = (const char **)a;
    const char **ib = (const char **)b;

    return (strcmp(*ia, *ib));
}

void kmers(struct fastatools *f, char **av)
{
    int i = 0;

    f->k_mers = my_getnbr(av[2]);
    if (f->k_mers == 1)
        display_4_1();
    else {
        test_for_malloc_kmers(f);
        i = execute_4(f);
        f->nb_line_malloc_second = i;
        qsort(f->second_tab, i + 1, sizeof(char *), compare);
        print_second_tab(f);
    }
}