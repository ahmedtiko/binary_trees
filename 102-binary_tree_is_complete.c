#include "binary_trees.h"

int binary_tree_last_level_filled(const binary_tree_t *tree, size_t height, size_t level);

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_size - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height, size;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);

	if (size == (1U << height) - 1)
		return (1);

	if (size < (1U << height) - 1)
		return (0);

	return (binary_tree_last_level_filled(tree, height, 0));
}

/**
 * binary_tree_last_level_filled - Checks if the last level is filled from left to right
 * @tree: Pointer to the root node of the tree
 * @height: Height of the tree
 * @level: Current level being checked
 *
 * Return: 1 if the last level is filled from left to right, 0 otherwise
 */
int binary_tree_last_level_filled(const binary_tree_t *tree, size_t height, size_t level)
{
	if (tree == NULL)
		return (1);

	if (level == height - 1)
		return (1);

	if (tree == NULL)
		return (0);

	return (binary_tree_last_level_filled(tree->left, height, level + 1) &&
			binary_tree_last_level_filled(tree->right, height, level + 1));
}
