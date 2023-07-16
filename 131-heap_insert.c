#include "binary_trees.h"
#include <stdlib.h>

/**
* heap_insert - Inserts a value into a Max Binary Heap.
*
* @root: Double pointer to the root node of the Heap.
* @value: Value to be inserted.
*
* Return: Pointer to the created node, or NULL on failure.
*/
heap_t *heap_insert(heap_t **root, int value)
{
heap_t *new_node, *parent;

if (root == NULL)
return (NULL);

new_node = binary_tree_node(NULL, value);
if (new_node == NULL)
return (NULL);

if (*root == NULL)
{
*root = new_node;
return (new_node);
}

parent = *root;
while (parent->left && parent->right)
{
if (parent->left && parent->right)
{
if (parent->left->n > parent->right->n)
parent = parent->left;
else
parent = parent->right;
}
else if (parent->left && parent->left->n > value)
parent = parent->left;
else if (parent->right && parent->right->n > value)
parent = parent->right;
else
break;
}

if (parent->left == NULL)
parent->left = new_node;
else
parent->right = new_node;

new_node->parent = parent;

while (new_node->parent && new_node->n > new_node->parent->n)
{
int temp = new_node->n;
new_node->n = new_node->parent->n;
new_node->parent->n = temp;
new_node = new_node->parent;
}

return (new_node);
}
