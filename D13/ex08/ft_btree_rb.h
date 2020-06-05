#ifndef __FT_BTREE_RB_H__
# define __FT_BTREE_RB_H__

typedef		struct		s_rb_node  t_rb_node;
typedef		enum		e_rb_color t_rb_color;
enum		e_rb_color
{
	RB_BLACK,
	RB_RED
};

struct		s_rb_node
{
	t_rb_node	*parent;
	t_rb_node	*left;
	t_rb_node	*right;
	void		*data;
	t_rb_color	color;
};

#endif