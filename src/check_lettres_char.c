/*
** EPITECH PROJECT, 2020
** check_lettres_char
** File description:
** check_lettres_char
*/

#include "../include/fastatools.h"

int check_char(char *string, int i)
{
    if (string[i] != 'A' && string[i] != 'T' && string[i] != 'G' &&
        string[i] != 'C' && string[i] != 'N' && string[i] != 'a'
        && string[i] != 't' && string[i] != 'g' && string[i] != 'c'
        && string[i] != 'n' && string[i] != '\n' && string[i] != ' ')
        return (1);
    if (string[i] == 'A' || string[i] == 'T' || string[i] == 'G' ||
    string[i] == 'C' || string[i] == 'N' || string[i] == 'a'
    || string[i] == 't' || string[i] == 'g' || string[i] == 'c'
    || string[i] == 'n' || (string[i] == '\n' && string[i + 1] == '>'))
        return (2);

    return (0);
}

int remove_char(char *string, int i)
{
    if (string[i] == '\n' && string[i + 1] != '>') {
        while (string[i] == '\n' && string[i + 1] != '>') {
            i++;
        }
    }
    if (string[i] == ' ') {
        while (string[i] == ' ')
            i++;
    }

    return (i);
}

int remove_not_correct_char(char *string, int i)
{
    if (check_char(string, i) == 1) {
        while (check_char(string, i) == 1)
            i++;
    }

    return (i);
}