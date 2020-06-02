#include "ft_btree.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

t_btree		*btree_create_node(void *item);

void 		btree_insert_data(t_btree **root, void *item,
							  int (*cmpf)(void *, void *));

void		*btree_search_item(t_btree *root, void *data_ref,
							   int (*cmpf)(void *, void *));

int			btree_level_count(t_btree *root);

void		btree_apply_by_level(t_btree *root, void (*applyf)(void *item,
						 		 int current_level, int is_first_elem));

int 		ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2++)
	{
		if (*s1++ == 0)
			return 0;
	}
	return (*s1 - *--s2);
}

void		btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return;
	applyf(root->key);
	btree_apply_prefix(root->left, applyf);
	btree_apply_prefix(root->right, applyf);
}

void 		btree_apply_infix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return;
	btree_apply_infix(root->left, applyf);
	applyf(root->key);
	btree_apply_infix(root->right, applyf);
}

void		btree_apply_suffix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
		return;
	btree_apply_suffix(root->left, applyf);
	btree_apply_suffix(root->right, applyf);
	applyf(root->key);
}

void		ft_putstr_plus_space(char *str)
{
	char 	c;
	
	while (*str)
		write(1, str++, 1);
	c = ' ';
	write(1, &c, 1);
}
void 		exclam(void *item, int current_level, int is_first_elem)
{
	char 	*str;

	str = item;
	while (*str)
	{
		str++;
	}
	while(current_level--)
	{
		if (is_first_elem)
			*str++ = '#';
		else
			*str++ = '!';
	}
	*str = 0;
}
# define LENGTH 10
int			main(void)
{
	t_btree *root;
	//t_btree *node;
	char numbers[8][LENGTH] = {"d", "b", "f", "a", "c", "e", "g", "x"};
	/*	Test for btree_create_node();
	node = btree_create_node("CATHOLE");
	printf("%s", (char *)node->key);
	*/
	root = NULL;
	//create a tree
	for(int i = 0; i < 8; i++)
	{
		btree_insert_data(&root, numbers[i], (int (*)(void *, void *))ft_strcmp);
	}
	/*	check the correctness of the tree and check the "btree_apply_*() functions
	printf("\n======btree_apply_prefix:\n");
	btree_apply_prefix(root, *(void (*)(void *))ft_putstr_plus_space);

	printf("\n======btree_apply_infix:\n");
	btree_apply_infix(root, *(void (*)(void *))ft_putstr_plus_space);

	printf("\n======btree_apply_suffix:\n");
	btree_apply_suffix(root, *(void (*)(void *))ft_putstr_plus_space);
	*/
	/////////////////////////////////////////
	/*	Test the btree_search_item() function
	node = btree_search_item(root, "a", (int (*)(void *, void *))ft_strcmp);
	printf("%s\n", (char *)node->key);
	printf("%s\n", (char *)node->parent->key);
	*/
	/////////////////////////////////////////
	/*	Test the btree_level_count() function
	int depth;
	depth = btree_level_count(root);
	printf("%d", depth);
	*/
	// Test the btree_apply_by_level() function
	btree_apply_by_level(root, exclam);
	for(int i = 0; i < 8; i++)
	{
		printf("%s", numbers[i]);
	}
	return 0;
}