#include "ft_btree.h"
#include "ft_btree_rb.h"
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

void		rb_insert(struct s_rb_node **root, void *data, 
						  int (*cmpf)(void *, void *));

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

void 		rb_btree_apply_infix(t_rb_node *root, void (*applyf)(void *))
{
	if (!root)
		return;
	rb_btree_apply_infix(root->left, applyf);
	applyf(root->data);
	rb_btree_apply_infix(root->right, applyf);
}

void 		rb_btree_check_color_infix(t_rb_node *root)
{
	if (!root)
		return;
	rb_btree_check_color_infix(root->left);
	printf("%d ", root->color);
	rb_btree_check_color_infix(root->right);
}

# define LENGTH 10
# define ARRAY 8
int			main(void)
{
	//t_btree *root;
	//t_btree *node;
	t_rb_node *root;
	char numbers[ARRAY][LENGTH] = {"q", "a", "f", "d", "c", "e", "x", "n"};// "n"};//"x"};
	/*	Test for btree_create_node();
	node = btree_create_node("CATHOLE");
	printf("%s", (char *)node->key);
	*/
	root = NULL;
	/////////////////////////////////////////
	/*create a simple tree
	for(int i = 0; i < ARRAY; i++)
	{
		btree_insert_data(&root, numbers[i], (int (*)(void *, void *))ft_strcmp);
	}*/
	//create an red-black tree
	for(int i = 0; i < ARRAY; i++)
	{
		rb_insert(&root, numbers[i], (int (*)(void *, void *))ft_strcmp);
	printf("\n======rb_btree_apply_infix======\n");
	printf("\nROOT IS %s\n", (char *)root->data);
	rb_btree_apply_infix(root, *(void (*)(void *))ft_putstr_plus_space);
	printf("\n");
	rb_btree_check_color_infix(root);
	printf("\n");
	}
	/////////////////////////////////////////
	/*	check the correctness of the tree and check the "btree_apply_*() functions
	printf("\n======btree_apply_prefix======\n");
	btree_apply_prefix(root, *(void (*)(void *))ft_putstr_plus_space);
	
	printf("\n======btree_apply_infix======\n");
	btree_apply_infix(root, *(void (*)(void *))ft_putstr_plus_space);

	printf("\n======btree_apply_suffix======\n");
	btree_apply_suffix(root, *(void (*)(void *))ft_putstr_plus_space);
	printf("\n");
	*/
	/////////////////////////////////////////
	/*	Test the btree_search_item() function 
	node = btree_search_item(root, "d", (int (*)(void *, void *))ft_strcmp);
	if (!node)
		printf("No such item!\n");
	else
	{
		printf("node is %s\n", (char *)node->key);
		if (!node->parent)
			printf("And it's the root!\n");
		else
			printf("Papa is %s\n", (char *)node->parent->key);
	}
	*/
	/////////////////////////////////////////
	/*	Test the btree_level_count() function
	int depth;
	depth = btree_level_count(root);
	printf("%d", depth);
	*/
	/////////////////////////////////////////
	/* Test the btree_apply_by_level() function
	btree_apply_by_level(root, exclam);
	for(int i = 0; i < ARRAY; i++)
	{
		printf("%s", numbers[i]);
	}*/
	return 0;
}