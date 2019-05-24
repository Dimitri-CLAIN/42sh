/*
** EPITECH PROJECT, 2019
** search_key_word
** File description:
** search_key_word
*/

#include "my.h"

int check_word(char *input, char *key_word, int i)
{
    int j = 0;

    while (input[i] != '\0' && j != my_strlen(key_word)) {
        if (input[i] != key_word[j])
            return (FALS);
        i++;
        j++;
    }
    return (TRU);
}

int find_key_word(char *input, char *key_word)
{
    int i = 0;

    while (input[i] != '\0') {
        if (check_word(input, key_word, i) == TRU)
            return (TRU);
        i++;
    }
    return (FALS);
}

char *search_key_word(char *input, char **cmd)
{
    char *key_word = cmd[array_len(cmd) - 1];
    char **tmp = word_array(input, '\n');
    char *dest = my_strdup("", KEEP);
    int i = 0;

    while (tmp[i] != NULL) {
        if (find_key_word(tmp[i], key_word) == TRU)
            dest = my_strcat(my_strcat(dest, tmp[i],
            KEEP, KEEP), "\n", KEEP, KEEP);
        i++;
    }
    free_array(tmp);
    return (dest);
}
