/*
Files to turn in : btree_search_item.c, ft_btree.h
Allowed functions : Nothing

• Create a function btree_search_item which returns the first element related to
the reference data given as argument. The tree should be browsed using infix
traversal . If the element isn’t found, the function should return NULL.
*/
#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>

void		*btree_search_item(t_btree *root, void *data_ref,
						int (*cmpf)(void *, void *))
{
	t_btree *node;

	if (!root)
		return NULL;
	node = btree_search_item(t_btree *root->left, void *data_ref,
							 int (*cmpf)(void *, void *));
	if (node)
		return node;
	if (!cmpf(data_ref, root->key))
		return root;
	node = btree_search_item(t_btree *root->right, void *data_ref,
							 int (*cmpf)(void *, void *));
	return node;		
}
