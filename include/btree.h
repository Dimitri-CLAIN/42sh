/*
** EPITECH PROJECT, 2018
** btree
** File description:
** btree
*/

#ifndef _BTREE_H_
#define _BTREE_H_

typedef struct btree {
    char *sep;
    char *cmd;
    struct btree *left;
    struct btree *right;
} btree_t;

void     my_destroy_tree(btree_t *btree);
btree_t    *my_find_nb_in_btree(int nb, btree_t *node);
void    my_btree_create_new_node(btree_t **node, char *str);

#endif /* _BTREE_H_ */
