#ifndef __ALLFUNC_H__
# define __ALLFUNC_H__

void		ft_putchar(char c);
void		ft_putstr(char *str);
int			line_is_valid(char *str);
int			findrow(char **tab);
int			findsquare(char **tab, int row);
void		printtab(char **tab);
int 		ft_strlen(char *str);

#endif