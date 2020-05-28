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

void				set_to_sort(t_list **begin_list1, t_list **begin_list2,
								int (*cmp)())
{
	t_list			*insert;
	if (cmp((*begin_list1)->data, (*begin_list2)->data) > 0)
	{
		insert = *begin_list2;
		*begin_list2 = (*begin_list2)->next;
		insert->next = *begin_list1;
		*begin_list1 = insert;
	}
}

void 				finish(t_list *list1, t_list *list2, int (*cmp)())
{
	t_list			*insert;
	t_list			*place;
	t_list			*temp;

	if (!list2)
		return;
	if (!list1->next)
	{
		insert = list1;
		place = list2;
	}
	else if (!list2->next)
	{
		insert = list2;
		place = list1;
	}
	else printf("\nNEZHDANCHIK\n");
	if(cmp(place->data, insert->data) >= 0)
		insert->next = place;	
	else if(cmp(place->next->data, insert->data) > 0)
	{
		insert->next = place->next;
		place->next = insert;
	}
	else
		place->next->next = insert;
}

void				ft_sorted_list_merge(t_list **begin_list1, 
										t_list *begin_list2, int (*cmp)())
{ 															//aaa
	t_list			*list1;
	t_list			*insert;

	if (!begin_list2 || !begin_list1)
		return;
	if (!*begin_list1)
	{
		*begin_list1 = begin_list2;
		return;
	}
	set_to_sort(begin_list1, &begin_list2, cmp);
	list1 = *begin_list1;
	while (begin_list2 && begin_list2->next && list1->next)
	{
		if(cmp(list1->next->data, begin_list2->data) >= 0)
		{
			insert = begin_list2;
			begin_list2 = begin_list2->next;
			insert->next = list1->next;
			list1->next = insert;
		}
		list1 = list1->next;
	}
	finish(list1, begin_list2, cmp);
}
