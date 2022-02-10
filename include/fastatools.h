/*
** EPITECH PROJECT, 2020
** fastatools.h
** File description:
** fastatools.h
*/

#ifndef FASTATOOLS_H
#define FASTATOOLS_H

struct fastatools{
    char **tab;
    char **second_tab;
    int nb_lines_malloc;
    int nb_line_malloc_second;
    int k_mers;
    int opt_4;
};

struct utils{
    int i;
    int x;
    int y;
};

void check_what_to_do(char **av, struct fastatools *f);
int my_getnbr(char const *str);
void malloc_tab_lines(char *string, struct fastatools *f);
void malloc_tab(char *string, struct fastatools *f);
void display(struct fastatools *f);
void reorganize_string(char *string, struct fastatools *f);
int my_putchar(char c);
char my_putstr(char *str);
int remove_not_correct_char(char *string, int i);
int check_lettres(char *string, int i);
int remove_char(char *string, int i);
int check_char(char *string, int i);
void getline_file(struct fastatools *f);
char *put_all_in_string(struct fastatools *f);
char *my_strduplicate(char *src);
int  my_strlen(char *str);
void display_4_1(void);
void kmers(struct fastatools *f, char **av);
void print_second_tab(struct fastatools *f);
int coding_sequences(struct fastatools *f);
int compare(const void *a, const void *b);
int check_atg_characters(struct fastatools *f, int x, int y);
void malloc_cod_sequences_y(struct fastatools *f);
void malloc_cod_sequences_x(struct fastatools *f);
void print_second_tab_cod_sqc(struct fastatools *f);
int check_end_characters(struct fastatools *f, int x, int y);
int my_strcmp(const char *s1, const char *s2);
int my_strcmp_n(const char *s1, const char *s2, int n);
void check_tab(struct fastatools *f);
int my_strlen_kmers(char *str);
void malloc_kmers_tab(struct fastatools *f, int y);
void check_c_g_n(struct fastatools *f, int y, int x);
void print_correctly(struct fastatools *f, int y, int x);

#endif