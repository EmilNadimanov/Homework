/*
• Create a function btree_apply_prefix which applies the function given as argu-
ment to the item of each node, using prefix traversal to search the tree.
*/
#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>

void		btree_apply_prefix(t_btree *root, void (*applyf)(void *))
}
	if (!root)
		return;
	applyf(root->key);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}
