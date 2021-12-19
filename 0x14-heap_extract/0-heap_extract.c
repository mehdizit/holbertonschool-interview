#include "binary_trees.h"

/**
 * heap_extract - extracts the root node from a Max-heap
 * @root: Address of the root pointer
 * Return: returns the root value or 0 on failure
 */
int heap_extract(heap_t **root)
{
	int i, n, size;
	heap_t **array;

	if (!root || !*root)
		return (0);
	n = (*root)->n;
	size = get_size(*root);
	array = malloc(1024 * sizeof(heap_t *));
	if (!array)
		return (0);
	for (i = 0; i < size; i++)
		array[i] = NULL;
	heap_to_array(array, *root, 0);
	if (array[size - 1] == (*root))
	{
		free(array);
		free(*root);
		*root = NULL;
		return (n);
	}
	(*root)->n = array[size - 1]->n;
	if (array[size - 1]->parent->left == array[size - 1])
		array[size - 1]->parent->left = NULL;
	else
		array[size - 1]->parent->right = NULL;
	free(array[size - 1]);
	free(array);
	rebuild_heap(*root);
	return (n);
}

/**
 * get_size - recursively counts the size of a heap
 * @root: the first node of the heap
 * Return: returns the size of the heap
 */
int get_size(heap_t *root)
{
	return (root ? 1 + get_size(root->left) + get_size(root->right) : 0);
}

/**
 * heap_to_array - arranges a heap in an array
 * @array: the array
 * @root: the first node of the heap
 * @index: the index of the array to fill
 */
void heap_to_array(heap_t **array, heap_t *root, int index)
{
	array[index] = root;
	if (root)
	{
		heap_to_array(array, root->left, (index * 2) + 1);
		heap_to_array(array, root->right, (index * 2) + 2);
	}
}

/**
 * rebuild_heap - rebuilds a heap
 * @node: root of the heap
 */
void rebuild_heap(heap_t *node)
{
	int temp;

	if (!node->left)
	{
		return;
	}
	else if (!node->right || node->left->n >= node->right->n)
	{
		if (node->n < node->left->n)
		{
			temp = node->n;
			node->n = node->left->n;
			node->left->n = temp;
		}
		rebuild_heap(node->left);
	}
	else if (node->left->n < node->right->n)
	{
		if (node->n < node->right->n)
		{
			temp = node->n;
			node->n = node->right->n;
			node->right->n = temp;
		}
		rebuild_heap(node->right);
	}
}