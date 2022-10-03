#include "binary_trees.h"

/**
 * binary_tree_height - Function that measures the height of a binary tree
 * @tree: Root node of the tree to meadure the height
 *
 * Return: Height of the node
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t levelr = 0, levell = 0;

	if (!tree)
		return (0);

	levell = binary_tree_height(tree->left);
	levelr = binary_tree_height(tree->right);

	return (levelr > levell ? levelr + 1 : levell + 1);
}

/**
 * print_level - print the specificated level.
 * @tree: Root node of the tree to meadure the height
 * @level: The level to print.
 * @func: The print function.
 * Return: Nothing
 */
void print_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 1)
		(func)(tree->n);
	else if (level > 1)
	{
		print_level(tree->left, level - 1, func);
		print_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - Print for level order.
 * @tree: Root node of the tree to meadure the height
 * @func: The print function.
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int he = 0, i = 0;

	if (!tree || !func)
		return;

	he = binary_tree_height(tree);

	for (i = 1; i <= he; i++)
		print_level(tree, i, func);
}
