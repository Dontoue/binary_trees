#include "binary_trees.h"

avl_t *avl_remove(avl_t *root, int value);
/**
 * avl_remove - Removes a node from an AVL tree.
 *
 * @root: Pointer to the root node of the tree.
 * @value: Value to remove from the tree.
 *
 * Return: Pointer to the new root node after removing the value.
 */
avl_t *avl_remove(avl_t *root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root->n)
        root->left = avl_remove(root->left, value);
    else if (value > root->n)
        root->right = avl_remove(root->right, value);
    else
    {
        avl_t *temp;

        if (root->left == NULL || root->right == NULL)
        {
            temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
            {
                *root = *temp;
                if (root->left != NULL)
                    root->left->parent = root;
                if (root->right != NULL)
                    root->right->parent = root;
            }
            free(temp);
        }
        else
        {
            temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;
            root->n = temp->n;
            root->right = avl_remove(root->right, temp->n);
        }
    }

    if (root == NULL)
        return NULL;

    root->parent = NULL;

    int balance = binary_tree_balance(root);

    if (balance > 1 && binary_tree_balance(root->left) >= 0)
        return binary_tree_rotate_right(root);

    if (balance > 1 && binary_tree_balance(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return binary_tree_rotate_right(root);
    }

    if (balance < -1 && binary_tree_balance(root->right) <= 0)
        return binary_tree_rotate_left(root);

    if (balance < -1 && binary_tree_balance(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return binary_tree_rotate_left(root);
    }

    return root;
}
