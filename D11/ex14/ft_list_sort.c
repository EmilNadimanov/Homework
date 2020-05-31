#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
• Create the function ft_list_sort which sorts the list’s contents by ascending order
by comparing two links thanks to a function that can compare the data held in those
two links. 
For example, the function cmp could be ft_strcmp...
*/

void			ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list		*min;
	t_list		*check1;
	t_list		*check2;
	void		*temp;

	if (!*begin_list || !begin_list)
		return;
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
