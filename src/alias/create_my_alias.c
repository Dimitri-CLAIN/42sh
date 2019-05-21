/*
** EPITECH PROJECT, 2019
** create my aliases
** File description:
** create_my_alias
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

int check_my_alias(char *cmd)
{
    //trovuer des cas d'erreur
    //si il y a des ' ou " et " "
    return (0);
}

char *get_file(char *name, char *path)
{
    struct stat sb;
    char *file = NULL;

    file = my_strcat(path, name, FREE, FREE);
    if (stat(cmd, &sb) == -1)
        return (NULL);
    if (S_ISDIR(sb.st_mode) == 1) {
        return (file);
    return (NULL);
}

int create_write_my_file(char *name, char *cmd)
{
    char *file = NULL;
    int fd = 0;

    file = get_file(name, my_strdup("./src/alias/", KEEP));
    if (file == NULL)
        return (84);
    fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1)
        return (84);
    write(fd, cmd, my_strlen(cmd));
    close(fd);
    return (0);
}

int write_alias()
{
    if (check_my_alias() == 84)
        return (84);
    if (create_write_my_file(name, cmd) == 84)
        return (84);
    //Faire un check pour voir si l'alias est correct
    //commande principale "alias" qui ecrie l'alias depuis le shell
}