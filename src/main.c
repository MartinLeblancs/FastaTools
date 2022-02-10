/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "../include/fastatools.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int part_of_error_handling(int ac, char **av)
{
    if (ac <= 1 || ac > 3)
        exit (84);
    if (my_getnbr(av[1]) < 1 || my_getnbr(av[1]) > 7)
        exit (84);
    return (0);
}

int error_handling(int ac, char **av)
{
    part_of_error_handling(ac, av);
    if (my_getnbr(av[1]) == 4) {
        if (ac != 3)
            return (84);
        for (int i = 0; av[2][i] != '\0'; i++) {
            if (av[2][i] < '0' || av[2][i] > '9')
                return (84);
        }
    }
    else {
        if (ac == 3)
            return (84);
    }
    return (0);
}

void free_struct(struct fastatools *f)
{
    int i = 0;

    free(f->tab);
    free(f);
}

void initialized_struct(struct fastatools *f)
{
    f->tab = NULL;
    f->second_tab = NULL;
    f->nb_lines_malloc = 0;
    f->nb_line_malloc_second = 0;
    f->k_mers = 0;
    f->opt_4 = 0;
}

int main(int ac, char **av)
{
    int i = 0;
    char *string = "\0";
    struct fastatools *f = malloc(sizeof(struct fastatools));
    initialized_struct(f);
    if (error_handling(ac, av) == 84) {
        write(1, "Error in arguments\n", 19);
        return (84);
    }
    getline_file(f);
    string = put_all_in_string(f);
    free(f->tab);
    malloc_tab(string, f);
    malloc_tab_lines(string, f);
    reorganize_string(string, f);
    check_tab(f);
    check_what_to_do(av, f);
    free(string);
    free_struct(f);
    return (0);
}