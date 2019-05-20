/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** return_nb_in_str
*/


int    my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int value = 1;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            value *= -1;
        }
        i += 1;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        nb = nb * 10 + str[i] -48;
        i += 1;
    }
    return (nb * value);
}
