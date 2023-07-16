#include "binary_trees.h"

/**
* binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
*
* @tree: Pointer to the root node of the tree to check.
*
* Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise.
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

/* Check if the current node has children */
if (tree->left != NULL && tree->right != NULL)
{
/* Check if the left child violates the Max Heap property */
if (tree->n < tree->left->n)
return (0);

/* Check if the right child violates the Max Heap property */
if (tree->n < tree->right->n)
return (0);

/* Recursively check the left and right subtrees */
if (!binary_tree_is_heap(tree->left) || !binary_tree_is_heap(tree->right))
return (0);
}
else if (tree->left != NULL)
{
/* Check if the left child violates the Max Heap property */
if (tree->n < tree->left->n)
return (0);

/* Recursively check the left subtree */
if (!binary_tree_is_heap(tree->left))
return (0);
}
else if (tree->right != NULL)
{
/* Check if the right child violates the Max Heap property */
if (tree->n < tree->right->n)
return (0);

/* Recursively check the right subtree */
if (!binary_tree_is_heap(tree->right))
return (0);
}

return (1);
}



