#ifndef __FT_LIST_H__
# define __FT_LIST_H__

typedef	struct	s_list	t_list;

struct 			s_list
{
	void		*data;
	t_list		*next;
};
#endif