/*
** EPITECH PROJECT, 2019
** fct_cd
** File description:
** function cd
*/

#include "my.h"

void cd_home(mysh_t *info)
{
    char *tmp = NULL;

    if ((tmp = cpy_str_env("HOME", info->env)) != NULL)
        chdir(tmp);
    else
        my_putstr_error("cd: No home directory.\n");
}

void check_error_cd(struct stat sb, char *path)
{
    if (S_ISDIR(sb.st_mode) != 1 && access(path, R_OK) == TRUE) {
        my_putstr_error(path);
        my_putstr_error(": Not a directory.\n");
    } else {
        my_putstr_error(path);
        my_putstr_error(": No such file or directory.\n");
    }
}

void do_the_fct_cd(char **tmp, mysh_t *info)
{
    struct stat sb;

    (void)info;
    stat(tmp[1], &sb);
    if (S_ISDIR(sb.st_mode) == 1)
        chdir(tmp[1]);
    else
        check_error_cd(sb, tmp[1]);
}

void check_cd(char *cmd, mysh_t *info)
{
    char **tmp = my_str_to_word_array(cmd, ' ', KEEP);

    if (tmp[1][0] == '~') {
        if (find_str_env("HOME", info->env) == TRUE)
            tmp[1] = my_strdup(get_path_home(tmp[1], info->env), FREE);
    } else if (my_strcmp(tmp[1], "-") == TRUE) {
        if (find_str_env("OLDPWD", info->env) == TRUE &&
            cpy_str_env("OLDPWD", info->env) != NULL) {
            tmp[1] = my_strdup(cpy_str_env("OLDPWD", info->env), FREE);
            chdir(tmp[1]);
            free_array(tmp);
            return;
        }
    }
    if (access(tmp[1], R_OK) == -1) {
        my_putstr_error(tmp[1]);
        my_putstr_error(": No such file or directory.\n");
    } else
        do_the_fct_cd(tmp, info);
    free_array(tmp);
}

void fct_cd(char *cmd, mysh_t *info)
{
    char **tmp = my_str_to_word_array(cmd, ' ', KEEP);

    if (array_len(tmp) > 2)
        my_putstr_error("cd: Too many arguments.\n");
    else if (array_len(tmp) == 1)
        cd_home(info);
    else
        check_cd(cmd, info);
    change_path_env(info);
    free_array(tmp);
}
