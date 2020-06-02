/*
• Create a function btree_apply_suffix which applies the function given as argu-
ment to the item of each node, using suffix traversal to search the tree.
*/
#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>


void		btree_apply_suffix(t_btree *root, void (*applyf)(void *))
}
	if (!root)
		return;
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
	applyf(root->key);
}
