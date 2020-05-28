#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>
/*
• Create the function ft_list_find which returns the address of the first link, whose
data is "equal" to the reference data.
*/

t_list			*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (!cmp(begin_list->data, data_ref))
			break;
		begin_list = begin_list->next;
	}
	return begin_list;
}
