#include "binary_trees.h"
/**
 * height - Measures the height of a binary tree
 * @tree: Pointer to the node to measures the height
 * Return: The height of the tree starting at node @tree
 */
int height(binary_tree_t *tree)
{
	int hl, hr;

	if (!tree)
		return (-1);
	hl = height(tree->left);
	hr = height(tree->right);
	return (hl > hr ? hl + 1 : hr + 1);
}
/**
 * compare_all_left_children -  compares the values of tree node
 * to all nodes of the left subtree
 * @tree: pointer to root node of the subtree
 * @child: pointer to the node of left child
 * Return: 1 if all values in left subtree are less than the value of tree,
 * 0 if not
 */
int compare_all_left_children(const binary_tree_t *tree, binary_tree_t *child)
{
	if (!child)
		return (1);
	if (tree->n <= child->n)
		return (0);
	return (1 * compare_all_left_children(tree, child->left)
			* compare_all_left_children(tree, child->right));
}
/**
 * compare_all_right_children -  compares the values of tree node
 * to all nodes of the right subtree
 * @tree: pointer to root node of the subtree
 * @child: pointer to the node of right child
 * Return: 1 if all values in right subtree are greater than the value of tree,
 * 0 if not
 */
int compare_all_right_children(const binary_tree_t *tree, binary_tree_t *child)
{
	if (!tree || !child)
		return (1);
	if (tree->n >= child->n)
		return (0);
	return (1 * compare_all_right_children(tree, child->left)
			* compare_all_right_children(tree, child->right));
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL tree
 * @tree: Pointer to the starting node
 * Return: 1 if valid, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int cmp_left, cmp_right;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);


	cmp_left = compare_all_left_children(tree, tree->left);
	cmp_right = compare_all_right_children(tree, tree->right);
	if (!cmp_left || !cmp_right)
		return (0);

	if (height(tree->left) - height(tree->right) > 1
			|| height(tree->left) - height(tree->right) < -1)
		return (0);

	if (!tree->left)
		return (1 * binary_tree_is_avl(tree->right));
	if (!tree->right)
		return (1 * binary_tree_is_avl(tree->left));
	return (1 * binary_tree_is_avl(tree->left) * binary_tree_is_avl(tree->right));
}