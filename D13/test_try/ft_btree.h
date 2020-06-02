#ifndef __FT_BTREE_H__
# define __FT_BTREE_H__

typedef	struct	s_btree	t_btree;

struct			s_btree
{
	t_btree		*parent;
	t_btree		*left;
	t_btree		*right;
	void		*key;
};

typedef	struct	s_line	t_line;

struct			s_line
{
	t_btree		**line;
	int			head;
	int			tail;
	int			length;
	int			is_first;
};

#endif