#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - function that creates
 * a binary tree node
 * @parent: A pointer to the parent
 * @value: value
 *
 * Return: A pointer to the new node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *newnode;
newnode = malloc(sizeof(binary_tree_t));
if (newnode == NULL)
return (NULL);

newnode->n = value;
newnode->left = NULL;
newnode->right = NULL;
newnode->parent = NULL;
if (parent)
newnode->parent = parent;

return (newnode);
}
