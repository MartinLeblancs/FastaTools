/*
** EPITECH PROJECT, 2020
** check_what_to_do
** File description:
** check_what_to_do
*/

#include "../include/fastatools.h"
#include <stdlib.h>

void execute_2(struct fastatools *f)
{
    int y = 0;
    int x = 0;

    while (y <= f->nb_lines_malloc - 2) {
        x = 0;
        if (y % 2 == 0)
            my_putstr(f->tab[y]);
        else {
            for (; f->tab[y][x] != '\0'; x++) {
                if (f->tab[y][x] == 'T')
                    my_putchar('U');
                else
                    my_putchar(f->tab[y][x]);
            }
        }
        y++;
    }
    my_putchar('\n');
}

void execute_3(struct fastatools *f)
{
    int y = 0;
    int x = 0;

    while (y <= f->nb_lines_malloc - 2) {
        x = 0;
        if (y % 2 == 0)
            my_putstr(f->tab[y]);
        else {
            x = (my_strlen(f->tab[y]));
            while (x != -1) {
                print_correctly(f, y, x);
                x--;
            }
            my_putchar('\n');
        }
        y++;
    }
}

void check_opt_1_3(char **av, struct fastatools *f)
{
    if (my_getnbr(av[1]) == 1)
        display(f);
    if (my_getnbr(av[1]) == 2)
        execute_2(f);
    if (my_getnbr(av[1]) == 3)
        execute_3(f);
}

void check_what_to_do(char **av, struct fastatools *f)
{
    int i = 0;

    check_opt_1_3(av, f);
    if (my_getnbr(av[1]) == 4)
        kmers(f, av);
    if (my_getnbr(av[1]) == 5) {
        malloc_cod_sequences_y(f);
        i = coding_sequences(f);
        qsort(f->second_tab, i, sizeof(char *), compare);
        f->second_tab[i] = NULL;
        print_second_tab_cod_sqc(f);
    }
}