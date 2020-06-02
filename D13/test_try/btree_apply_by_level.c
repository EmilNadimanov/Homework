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
#include <stdio.h>

int			btree_level_count(t_btree *root)
{
	int		depth_l;
	int		depth_r;
	int		max;
	t_btree	*node;

	if (!root)
		return 0;
	depth_l = 0;
	depth_l = btree_level_count(root->left);
	depth_r = btree_level_count(root->right);
	if (!root->left && !root->right)
	{
		node = root;
		max = 0;
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

void		enqueue(t_line *q, t_btree *node)
{
	if (!node)
		return;
	q->line[q->tail] = node;
	if (q->tail == q->length)
		q->tail = 0;
	else q->tail = q->tail + 1;
}

t_btree *	dequeue(t_line *q)
{
	t_btree *node;
	
	node = q->line[q->head];
	q->line[q->head] = NULL;
	if (q->head == q->length)
		q->head = 0;
	else 
		q->head = q->head + 1;
	return node;
}

int			get_param(t_btree *node, int flag)
{
	int is_first;
	int level;
	
	if (flag)
	{
		level = 0;
		while (node->parent)
		{
			level++;
			node = node->parent;
		}
		return level;
	}
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
	t_line	*q;
	t_btree	*node;

	if (!root)
		return;
	q = malloc(sizeof(t_line));
	q->length = btree_level_count(root) - 1;
	q->length = q->length * q->length;
	q->line = malloc(sizeof(t_btree *) * q->length + 1);
	q->head = 0;
	q->tail = q->head;
	enqueue(q, root);
	while (q->tail != q->head)
	{
		node = dequeue(q);
		if (node)
			applyf(node->key, get_param(node, 1), get_param(node, 0));
		enqueue(q, node->left);
		enqueue(q, node->right);
	}
	free(q->line);
	free(q);
}
