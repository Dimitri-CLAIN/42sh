/*
** EPITECH PROJECT, 2019
** str_is_alpha_num
** File description:
** str is alphanumeric
*/

int str_is_alphanum(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') &&
            (str[i] < '0' || str[i] > '9'))
            return (0);
        i++;
    }
    return (1);
}