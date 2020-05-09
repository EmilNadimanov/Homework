#include <unistd.h>
#include <stdlib.h>

void ft_putchar(char c);

int main(int argc, char **argv)
{
    int i;
	char *arg;

	i = 1;
	while (i < argc)
    {
        arg = argv[i++];
        while(*arg)
            ft_putchar(*arg++);
        ft_putchar('\n');
    }
    return 0;
}
