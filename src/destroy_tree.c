/*
** EPITECH PROJECT, 2018
** test
** File description:
** tes
*/

#include <stdlib.h>
#include <stdio.h>
#include "btree.h"

void     my_destroy_tree(btree_t *btree)
{
    if (btree != NULL) {
        my_destroy_tree(btree->left);
        my_destroy_tree(btree->right);
    } else
        return;
    if (btree->cmd != NULL)
        free(btree->cmd);
    if (btree->sep != NULL) {
        free(btree->sep);
        free(btree);
    }
}