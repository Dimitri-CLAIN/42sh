/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** mysh_term
*/

#include "my.h"

void check_exit(char *cmd, mysh_t *info)
{
    char **tmp = my_str_to_word_array(cmd, ' ', KEEP);

    if (my_strcmp(tmp[0], "exit") == TRU) {
        if (array_len(tmp) == 1)
            info->return_value = 0;
        else if (array_len(tmp) == 2 && isnum(tmp[1]) == FALS)
            info->return_value = my_getnbr(tmp[1]);
        else
            my_putstr_error("exit: Expression Syntax.\n");
    }
}

int get_input_term(char **input, char ***tab)
{
    if (*input == NULL ) {
        my_putstr("exit\n");
        return (-1);
    }
    *input = my_epurstr(my_strdup(*input, FREE), " \n \"\t", FREE);
    if (*input == NULL || *input[0] == '\0')
        *input = NULL;
    if (*input != NULL) {
        write_history(*input);
        if (*tab != NULL)
            free_array(*tab);
        *tab = read_file(".history");
    }
    return (0);
}