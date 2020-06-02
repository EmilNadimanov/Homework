/*
• Create a function btree_insert_data which inserts the element item into a tree.
The tree passed as argument will be sorted : for each node all lower elements are
located on the left side and all higher or equal elements on the right. We’ll also
pass a comparison function similar to strcmp as argument.

• The root parameter points to the root node of the tree. First time called, it should
point to NULL.
*/
#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_btree		*btree_create_node(void *item);

void		add_node(t_btree *node, t_btree *node_p,
					 int (*cmpf)(void *, void *))
{
	node->parent = node_p;
	if (cmpf(node->key, node_p->key) < 0)
		node_p->left = node;
	else
		node_p->right = node;
}
void 		btree_insert_data(t_btree **root, void *item,
							  int (*cmpf)(void *, void *))
{
	t_btree	*node;
	t_btree	*node_p;

	if (!root)
		return;
	else if (!*root)
	{
		*root = btree_create_node(item);
		return;
	}
	node = *root;
	while (node)
	{
		node_p = node;
		if (cmpf(item, node->key) < 0)
			node = node->left;
		else
			node = node->right;
		if (!node)
		{
			node = btree_create_node(item);
			add_node(node, node_p, cmpf);
			break;
		}
	}
}

/*	CLRS
void 		btree_insert_data(t_btree **root, void *item, 
							  int (*cmpf)(void *, void *))
}
	if (!root)
		return;
	else
	{
		t_btree node;
		t_btree node_p;
		
		node_p = NULL;
		node = *root;
		while(node)
		{
			node_p = node;
			if (cmpf(item, node->key) < 0)
				node = node->left;
			else
				node = node->right;
		}
		if (!node_p);
			*root = btree_create_node(item);
		else
		{
			node = btree_create_node(item);
			node->parent = node_p;
			if (cmpf(node->key, node_p->key) < 0)
				node_p->left = node;
			else
				node_p->right = node;
		}		
	}
}*/
