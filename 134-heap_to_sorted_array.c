#include "binary_trees.h"

/**
* heapify_down - Restores the Max Heap property by moving down the tree
* @node: Pointer to the current node
*/
void heapify_down(heap_t *node)
{
heap_t *largest = node->left;

if (node->right != NULL && node->right->n > largest->n)
largest = node->right;

if (largest != NULL && largest->n > node->n)
{
int temp = node->n;
node->n = largest->n;
largest->n = temp;
heapify_down(largest);
}
}

/**
* heap_extract - Extracts the root node of a Max Binary Heap
* @root: Double pointer to the root node of the heap
*
* Return: Value stored in the root node, or 0 on failure
*/
int heap_extract(heap_t **root)
{
int extracted_value;
heap_t *last_node, *current_node;

if (root == NULL || *root == NULL)
return (0);

extracted_value = (*root)->n;
last_node = *root;
while (last_node->left != NULL || last_node->right != NULL)
{
if (last_node->right != NULL)
last_node = last_node->right;
else
last_node = last_node->left;
}

if (*root == last_node)
{
free(last_node);
*root = NULL;
return (extracted_value);
}

current_node = *root;
while (current_node->left != last_node && current_node->right != last_node)
{
if (last_node->parent->left != NULL && last_node->parent->left != last_node)
current_node = current_node->left;
else if (last_node->parent->right != NULL && last_node->parent->right != last_node)
current_node = current_node->right;
}

if (last_node->parent->left == last_node)
last_node->parent->left = NULL;
else
last_node->parent->right = NULL;

(*root)->n = last_node->n;
free(last_node);

heapify_down(*root);

return (extracted_value);
}

/**
* heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
* @heap: Pointer to the root node of the heap
* @size: Address to store the size of the array
*
* Return: Pointer to the sorted array of integers (in descending order)
*/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
size_t i, heap_size;
int *sorted_array;

if (heap == NULL || size == NULL)
return (NULL);

heap_size = binary_tree_size(heap);
sorted_array = malloc(heap_size *sizeof(int));
if (sorted_array == NULL)
return (NULL);

for (i = 0; i < heap_size; i++)
{
sorted_array[i] = heap_extract(&heap);
if (sorted_array[i] == 0)
{
free(sorted_array);
return (NULL);
}
}

*size = heap_size;
return (sorted_array);
}
