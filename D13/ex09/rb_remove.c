/*
Files to turn in : rb_remove.c, ft_btree_rb.h
Allowed functions : free

• Create a function rb_remove which removes a data from the the tree so that it
continues to respect a red and black tree’s restrictions. The argument root points
to the tree’s root node. We’ll also pass a comparison function similar to strcmp
as argument, as well as a pointer to function freef which will be called, with the
element of the tree to be deleted, as argument.

ПЯТЬ ПРАВИЛ КРАСНО-ЧЁРНЫХ ДЕРЕВЬЕВ
1) В ДЕРЕВЕ ЕСТЬ ЧЁРНЫЕ И КРАСНЫЕ УЗЛЫ
2) КОРЕНЬ ВСЕГДА ЧЁРНЫЙ
3) ЛИСТЬЯ ВСЕГДА ЧЁРНЫЕ
4) ПОСЛЕ КРАСНОГО ВСЕГДА СТОЯТ ДВА ЧЁРНЫХ УЗЛА
5) ОТ ВСЯКОГО УЗЛА ДО ВСЯКОГО ЛИСТА, ЯВЛЯЮЩЕГОСЯ ЕГО ПОТОМКОМ, ОДИНАКОВОЕ ЧИСЛО ЧЁРНЫХ УЗЛОВ
*/
#include "ft_btree_rb.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void		rotate(t_rb_node *node, char c, t_rb_node **root)
{
	t_rb_node *child;

	if (c == 'l')
	{
		child = node->right;
		node->right = child->left;
		if (child->left)
			child->left->parent = node;
		child->left = node;
	}
	else if (c == 'r')
	{
		child = node->left;
		node->left = child->right;
		if (child->right)
			child->right->parent = node;
		child->right = node;
	}
	child->parent = node->parent;
	if (!child->parent)
		*root = child;
	else if (node == node->parent->right)
		node->parent->right = child;
	else
		node->parent->left = child;
	node->parent = child;
}

void		rb_fixup(t_rb_node *node, t_rb_node **root)
{
	t_rb_node *uncle;

	while (node->parent && node->parent->color == RB_RED)//INSERT_FIXUP_RB, если батя красный (а вставленный узел тоже красный)
	{
		if (!node->parent->parent)
			break;
		else if (node->parent == node->parent->parent->left)//установили дядю
			uncle = node->parent->parent->right;
		else
			uncle = node->parent->parent->left;
		if (uncle && uncle->color == RB_RED) //Случай 1: дядя красный
		{
			uncle->color = RB_BLACK;
			node->parent->color = RB_BLACK;
			node = node->parent->parent;
			node->color = RB_RED;
		}
		else if (node->parent == node->parent->parent->left) //Случай 2
		{
			if (node == node->parent->right) //Случай 2-d
			{
				node = node->parent;
				rotate(node, 'l', root);
			}
			node->parent->color = RB_BLACK;//Случай 2-c
			node->parent->parent->color = RB_RED;
			rotate(node->parent->parent, 'r', root);
		}
		else if (node->parent == node->parent->parent->right)
		{
			if (node == node->parent->left)//Случай 2-b
			{
				node = node->parent;
				rotate(node, 'r', root);
			}
			node->parent->color = RB_BLACK;//Случай 2-d
			node->parent->parent->color = RB_RED;
			rotate(node->parent->parent, 'l', root);
		}
	}
	(*root)->color = RB_BLACK; //красим корень в чёрный
}
void rb_remove(struct s_rb_node **root, void *data,
			   int (*cmpf)(void *, void *), void (*freef)(void *))
{

}