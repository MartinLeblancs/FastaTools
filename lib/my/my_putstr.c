/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** my_putstr
*/

int my_putchar(char c);

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}
