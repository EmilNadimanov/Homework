/*
Files to turn in : btree_apply_by_level.c, ft_btree.
Allowed functions : malloc, free

• Create a function btree_apply_by_level which applies the function passed as
argument to each node of the tree. The tree must be browsed level by level. The
function called will take three arguments : 
	◦ The first argument, of type void *, will correspond to the node’s item ;
	◦ The second argument, of type int, corresponds to the level on which we find
  : 0 for root, 1 for children, 2 for grand-children, etc. ;
	◦ The third argument, of type int, is worth 1 if it’s the first node of the level,
  or worth 0 otherwise.
*/
#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>

void btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
						  int current_level, int is_first_elem))
{

}
