#include <stdlib.h>
#include <unistd.h>
/*
Нестандартная функция языка программирования Си, создающая копию 
указанной нуль-терминированной строки в куче (используя malloc) и 
возвращающая указатель на неё. Чтобы освободить место, используемое 
созданной копией, необходимо вызвать free.
*/

char	*ft_strdup(char *src)
{
	char	*str;
	int		i;
	int 	n;

	n = -1;
	i = -1;
	while (src[++i])
		;
	str = malloc(i * sizeof(char));
	if (!str)
		return NULL;
	while (++n <= i)
		str[n] = src[n];
	return str;
}
