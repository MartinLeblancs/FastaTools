/*
** EPITECH PROJECT, 2020
** strdup
** File description:
** strdup
*/

#include <stdlib.h>
#include "../../include/fastatools.h"

char *my_strduplicate(char *src)
{
    char *dest;
    int count = 0;

    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    for (count = 0; src[count] != '\0'; count++)
        dest[count] = src[count];
    dest[count] = '\0';
    return (dest);
}
