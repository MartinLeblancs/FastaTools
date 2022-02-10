/*
** EPITECH PROJECT, 2020
** coding_sequences
** File description:
** coding_sequences
*/

#include "../include/fastatools.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

void malloc_second_tab_cod_sqc(struct fastatools *f, int i, int len)
{
    f->second_tab = malloc(sizeof(char *) * i);
    for (int count = 0; count <= i; count++)
        f->second_tab[count] = malloc(sizeof(char) * len);
}

void malloc_cod_sequences_y(struct fastatools *f)
{
    int y = 0;
    int i = 0;
    int len = 0;
    int begin = 0;
    int line_len = 0;

    for (; y != f->nb_lines_malloc; y++) {
        if (y % 2 != 0) {
            begin = 0;
            line_len = my_strlen(f->tab[y]);
            for (int x = 0; x < line_len; x++) {
                if (check_atg_characters(f, x, y) == 1)
                    if (begin == 0)
                        begin = x;
                if (check_end_characters(f, x, y) == 1) {
                    if ((x - begin) % 3 != 0) {
                        begin = 0;
                        continue;
                    }
                    for (int j = begin; j < x; j++)
                        if (len < j)
                            len = j;
                    i++;
                    begin = 0;
                }
            }
        }
    }
    f->nb_line_malloc_second = i;
    malloc_second_tab_cod_sqc(f, i, len);
}

int check_end_characters(struct fastatools *f, int x, int y)
{
    return my_strcmp_n("TAA", f->tab[y] + x, 3) ||
    my_strcmp_n("TGA", f->tab[y] + x, 3) ||
    my_strcmp_n("TAG", f->tab[y] + x, 3);
}

int check_atg_characters(struct fastatools *f, int x, int y)
{
    return my_strcmp_n("ATG", f->tab[y] + x, 3);
}
int coding_sequences(struct fastatools *f) {
    int x = 0;
    int y = 0;
    int pos = 0;
    int i = 0;

    f->second_tab = malloc(sizeof(char *) * 1000);
    for (int z = 0; z <= 1000; z++)
        f->second_tab[z] = malloc(sizeof(char) * 1000);
    for (; y != f->nb_lines_malloc; y++) {
        x = 0;
        if (y % 2 != 0) {
            for (pos = 0; f->tab[y][x] != '\0'; x++) {
                if (check_atg_characters(f, x, y) == 1)
                    pos = x;
                if (check_end_characters(f, x, y) == 1) {
                    for (int j = 0; pos < x; j++, pos++)
                        f->second_tab[i][j] = f->tab[y][pos];
                    i++;
                    x = pos + 1;
                    pos = 0;
                }
            }
        }
    }
    return (i);
}

int coding_sequences2(struct fastatools *f)
{
    int y = 0;
    int i = 0;
    int begin = 0;
    int line_len = 0;

    for (; y != f->nb_lines_malloc; y++) {
        if (y % 2 != 0) {
            begin = 0;
            line_len = my_strlen(f->tab[y]);
            for (int x = 0; x < line_len; x++) {
                if (check_atg_characters(f, x, y) == 1)
                        begin = x;
                if (check_end_characters(f, x, y) == 1) {
                    for (int j = begin; j < x; j++)
                        f->second_tab[i][j - begin] = f->tab[y][j];
                    i++;
                    begin = 0;
                }
            }
        }
    }
    return (i);
}