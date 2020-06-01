/*
Files to turn in : btree_level_count.c, ft_btree.h
Allowed functions : Nothing
• Create a function btree_level_count which returns the size of the largest branch
passed as argument.
*/
#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>

int			btree_level_count(t_btree *root);
{
	int depth_l;
	int depth_r;
	int max;
	t_btree *node;

	if (!root)
		return 0;
	depth_l = btree_level_count(root->left);
	depth_r = btree_level_count(root->right);
	if (!root->left && !root->right)
	{
		node = root;
		while(node)
		{
			node = node->parent;
			max++;
		}
		return max;
	}
	else
		return max = (depth_l > depth_r) ? depth_l : depth_r;
}
