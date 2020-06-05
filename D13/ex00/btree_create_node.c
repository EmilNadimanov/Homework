/*
Files to turn in : btree_create_node.c, ft_btree.h
Allowed functions : malloc

• Create the function btree_create_node which allocates a new element. It should
initialise its item to the argument’s value, and all other elements to 0.
• The created node’s address is returned.
*/
#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>

t_btree		*btree_create_node(void *item)
{
	t_btree *node;

	node = malloc(sizeof(t_btree));
	node->key = item;
	node->left = 0;
	node->right = 0;
	node->parent = 0;
	return node;
}