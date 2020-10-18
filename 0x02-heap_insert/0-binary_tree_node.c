#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: A pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: A pointer to the new node or NULL if failed
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *newnode;
newnode = malloc(sizeof(binary_tree_t));

newnode->n = value;
newnode->left = NULL;
newnode->right = NULL;
if (parent)
newnode->parent = parent;

return(newnode);
}
