/*
** EPITECH PROJECT, 2020
** my_strlen_kmers
** File description:
** my_strlen_kmers
*/

int my_strlen_kmers(char *str)
{
    int i = 0;
    int count = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        count++;
        i++;
    }

    return (count);
}