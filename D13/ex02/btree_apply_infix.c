/*
Files to turn in : btree_apply_infix.c, ft_btree.h
Allowed functions : Nothing
Remarks : n/a
• Create a function btree_apply_infix which applies the function given as argument
to the item of each node, using infix traversal to search the tree.
*/
#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>

void 		btree_apply_infix(t_btree *root, void (*applyf)(void *))
}
	if (!root)
		return;
	btree_apply_prefix(root->left, applyf);
	applyf(root->key);
	btree_apply_prefix(root->right, applyf);
}
