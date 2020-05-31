#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>
/*
• Create the function ft_list_merge which places elements of a list begin2 at the
end of an other list begin1.
• Element creation is not authorised.
• Here’s how it should be prototyped :
void ft_list_merge(t_list **begin_list1, t_list *begin_list2);
*/

void		ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*current;

	if (!*begin_list1)
		*begin_list1 = begin_list2;
	else
	{
		current = *begin_list1;
		while (current->next)
			current = current->next;
		current->next = begin_list2;
	}
}
