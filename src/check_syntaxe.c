/*
** EPITECH PROJECT, 2019
** check_syntaxe
** File description:
** check_syntaxe
*/

#include "my.h"
#include <sys/stat.h>

void display_permission_denied(char *cmd)
{
    my_putstr_error(cmd);
    my_putstr_error(": Permission denied.\n");
}

void display_error_arch(void)
{
    my_putstr_error("Exec format error. Wrong Architecture.\n");
    exit(84);
}

int check_dir(char *cmd)
{
    struct stat sb;
    
    if (stat(cmd, &sb) == -1)
        return (FALSE);
    if (cmd[0] == '/') {
        if (S_ISDIR(sb.st_mode) == 1) {
            display_permission_denied(cmd);
            return (TRUE);
        }
    }
    else if ((cmd[0] == '.' && access(cmd, R_OK) == TRUE) ||
             (S_ISDIR(sb.st_mode) == 1)) {
        display_permission_denied(cmd);
        return (TRUE);
    }
    return (FALSE);
}

int check_first_access(char *cmd)
{
    struct stat sb;

    stat(cmd, &sb);
    if (is_buldin(cmd) == TRUE || (access(cmd, X_OK) == TRUE &&
        S_ISDIR(sb.st_mode) != 1))
        return (TRUE);
    return (FALSE);
}
