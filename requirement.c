/*
** EPITECH PROJECT, 2020
** my_strcapitalize
** File description:
** my_strcapitalize
*/

int check_number(char *str, int i)
{
    if (str[i - 1] >= '0' && str[i - 1] <= '9')
        return (1);
    else
        return (0);
}

int check_str_char(char *str, int i)
{
    if ((str[i] >= 'a' && str[i] <= 'z')) {
        return (1);
    }
    return (0);
}

int check_str_char2(char *str, int i)
{
    if (str[i - 1] < 'a' || str[i - 1] > 'z') {
        if (str[i - 1] < 'A' || str[i - 1] > 'Z')
            return (1);
    }
    return (0);
}

char *my_strcapitalize_synthesis(char *str)
{
    int i = 0;

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] = str[0] - 32;
    for (i = 1; str[i] != '\0'; i++) {
        if (check_str_char(str, i) == 1)
            if (check_str_char2(str, i) == 1) {
                if (check_number(str, i) != 1)
                    str[i] = str[i] - 32;
            }
    }
    return (str);
}