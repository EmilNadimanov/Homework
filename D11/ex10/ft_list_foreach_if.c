#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>
/*
• Create the function ft_list_foreach_if which applies a function given as argu-
 ment to the information held in some links of the list. A reference information as
 well as a comparative function should allow us to select the right links of the list :
 those that are "equal" to the reference information.
• Functions pointed by f and by cmp will be used as follows :
 (*f)(list_ptr->data);
 (*cmp)(list_ptr->data, data_ref);
For example, the function cmp could be ft_strcmp...
*/

void 		ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
							   void *data_ref, int (*cmp)())
{
	while (begin_list)
	{
		if (!cmp(begin_list->data, data_ref))
			f(begin_list->data);
		begin_list = begin_list->next;
	}
}
