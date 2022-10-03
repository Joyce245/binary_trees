#include "binary_trees.h"

/**
 * binary_trees_ancestor - Function that finds the uncle of a node
 * @first: First node
 * @second: Second node
 *
 * Return: Ancestor node
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *one = NULL, *two = NULL;

	if (!first || !second)
		return (NULL);

	one = (binary_tree_t *)first;
	while (one)
	{
		two = (binary_tree_t *)second;
		while (two)
		{
			if (one == two)
				return (one);
			two = two->parent;
		}
		one = one->parent;
	}
	return (NULL);
}
