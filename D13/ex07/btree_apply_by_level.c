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

int			count_bottom_nodes(t_btree *root)
{
	int bot_nodes;

	if (!root)
		return 0;
	bot_nodes = 0;
	bot_nodes += count_bottom_nodes(root->left);
	bot_nodes += count_bottom_nodes(root->right);
	if (!root->left && !root->right)
		bot_nodes++;
	return bot_nodes;
}

void		enqueue(t_line *q, t_btree *node)
{
	if (q->tail == q->head || !node)
		return;
	q->line[q->tail] = node;
	if (q->tail == q->length - 1)
		q->tail == 0;
	else q->tail = q->tail + 1;
}

void		dequeue(t_line *q)
{
	t_btree *node;

	if (q->head == q->tail)
		return;
	node = q->line[q->head];
	q->line[q->head] = NULL;
	if (q->head == q->length - 1)
		q->head == 0;
	else q->head = q->head + 1;
}

int			get_param(t_btree *node, int flag)
{
	if (!flag)
	{
		int level;

		level = 1;
		while (node->parent)
			level++;
		return level;
	}
	int is_first;

	is_first = 1;
	while (is_first && node->parent)
	{
		if (node == node->parent->left)
			node = node->parent;
		else
			is_first = 0;
	}
	return is_first;
}

void		btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
						 		 int current_level, int is_first_elem))
{
	int		save;
	t_line	*q;
	t_btree	node;

	if (!root)
		return;
	levels = btree_level_count;
	q->length = count_bottom_nodes(root);
	q->line = malloc(sizeof(t_btree *) * q->length);
	q->head = 0;
	q->tail = q->head;
	enqueue(q, root);
	while (		)
	{
		q->is_first = 1;
		while ()
		{
			node = dequeue(q);
			applyf(node, get_param(node, 0), get_param(node, 1);
			q->is_first = 0;
			enqueue(q, node->left);
			enqueue(q, node->right);
		}
	}
}
