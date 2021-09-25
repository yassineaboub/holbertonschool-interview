#include "binary_trees.h"

/**
 * check_avl -function
 * Desc: check_avl function check
 * @tree: pointer
 * @min: minimum value
 * @max: maximum value
 * @height: height of this tree
 * Return: true if is AVL else 0
 */
int check_avl(const binary_tree_t *tree, int min, int max, int *height)
{
	int h1 = 0, h2 = 0;

	if (!tree)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	if (!check_avl(tree->left, min, tree->n, &h1) ||
	    !check_avl(tree->right, tree->n, max, &h2))
		return (0);
	*height = MAX(h1, h2) + 1;
	return (ABS(h1 - h2) <= 1);
}

/**
 * binary_tree_is_avl - entry function
 * Desc: binary_tree_is_avl function
 * @tree: pointer
 * Return: 1 if tree is a valid AVL, and 0 otherwise
 *
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height;

	if (!tree)
		return (0);
	return (check_avl(tree, INT_MIN, INT_MAX, &height));
}
