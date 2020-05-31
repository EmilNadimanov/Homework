#ifndef __ALLFUNC_H__
# define __ALLFUNC_H__

#include <stdlib.h>
#include <unistd.h>

int			ft_is_num(char *str);
int			error(char *filename, int flag);
int			ft_strcmp(char *s1, char *s2);
int			is_num(char *str);
int			get_bytes(char *str, int merged);
void		ft_putstr(char *str);



#endif