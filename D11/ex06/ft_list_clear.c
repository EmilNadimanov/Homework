#include "ft_list.h"
#include <stdlib.h>
#include <unistd.h>

/*
• Create the function ft_list_clear which clears all links from the list.
• It’ll then assign the list’s pointer to null.
*/

void	ft_list_clear(t_list **begin_list)
{
	t_list		*pchelka;

	if (!begin_list || !*begin_list)
		return;
	while(*begin_list)
	{
		pchelka = (*begin_list)->next;
		free(*begin_list);
		*begin_list = pchelka;
	}
	*begin_list = NULL;
}
