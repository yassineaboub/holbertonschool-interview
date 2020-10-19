#include <stdlib.h>
#include "binary_trees.h"
/**
* bt_size - function that give the size
* @r: ptr to node.
* Return: function return 0
**/
size_t bt_size(const binary_tree_t *r)
{
size_t s_bnt = 0;
if (r == NULL)
return (0);
if (r->left != NULL)
s_bnt = s_bnt + bt_size(r->left);
if (r->right != NULL)
s_bnt = s_bnt + bt_size(r->right);
s_bnt = s_bnt + 1;
return (s_bnt);
}
/**
 * bt_perfect - function that checks if fnc is perfect
 * @tree: ptr to node
 * Return:  1 if true otherwise 0
 */
int bt_perfect(const binary_tree_t *r)
{
int lsize, rsize;
if (r == NULL)
return (0);
lsize = bt_size(r->left);
rsize = bt_size(r->right);
if (lsize == rsize)
return (1);
return (0);
}
/**
 * find_parent_heap - fnc that checks if parent grater than child
 * @s: ptr to node  of child
 * @f: ptr to node ofparent
 * Return:0
 */
void find_parent_heap(heap_t **s, heap_t **f)
{
heap_t *cl, *cr, *child = *s, *parent = *f;
cr = (*s)->right, cl = (*s)->left;
if (child->n > parent->n)
{
if (child->left)
child->left->parent = parent;
if (child->right)
child->right->parent = parent;
if (parent->left == child)
{
if (parent->right)
parent->right->parent = child;
child->right = parent->right;
child->left = parent;
}
else
{
parent->left->parent = child;
child->left = parent->left;
child->right = parent;
}
if (parent->parent)
{
if (parent->parent->left == parent)
parent->parent->left = child;
else
parent->parent->right = child;
}
else
{
*f = child;
}
child->parent = parent->parent;
parent->parent = child;
parent->left = cl;
parent->right = cr;
}
}
/**
 * heap_insert - make new tree
 * @root: pointer node to root , double ptr
 * @value: store value to insert
 * Return: The new node or null
 */
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *nnode;
if ((*root) == NULL)
{
*root = binary_tree_node(NULL, value);
return (*root);
}
if (bt_perfect(*root) || (!bt_perfect((*root)->left)))
{
if ((*root)->left != NULL)
{
nnode = heap_insert(&((*root))->left, value);
find_parent_heap(&((*root)->left), root);
return (nnode);
}
else
{
nnode = binary_tree_node(*root, value);
(*root)->left = nnode;
find_parent_heap(&((*root)->left), root);
return (nnode);
}
}
else
{
if ((*root)->right != NULL)
{
nnode = heap_insert(&((*root)->right), value);
find_parent_heap(&((*root)->right), root);
return (nnode);
}
else
{
nnode = binary_tree_node(*root, value);
(*root)->right = nnode;
find_parent_heap(&((*root)->right), root);
return (nnode);
}
}
return (NULL);
}
