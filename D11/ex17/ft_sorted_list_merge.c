#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
/*
• Create the function ft_sorted_list_merge which integrates the elements of a
sorted list begin2 in another sorted list begin1, so that begin1 remains sorted by
ascending order.
*/

void			ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*min;
	t_list	*check1;
	t_list	*check2;
	void	*temp;


	check1 = *begin_list;
	while (check1->next)
	{
		min = check1;
		check2 = check1;
		while (check2->next)
		{
			check2 = check2->next;
			if (cmp(min->data,check2->data) > 0)
				min = check2;
		}
		temp = check1->data;
		check1->data = min->data;
		min->data = temp;
		check1 = check1->next;
	}
}

void			ft_sorted_list_merge(t_list **begin_list1, 
									 t_list *begin_list2, int (*cmp)())
{
	t_list	*node;

	if (!*begin_list1 || !begin_list1 || !*begin_list2)
		return;
	node = *begin_list1;
	while (node->next)
		node = node->next;
	node->next = begin_list2;
	ft_list_sort(begin_list1, cmp);
}
