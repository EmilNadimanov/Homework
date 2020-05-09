#include <stdlib.h>
#include <unistd.h>

void   ft_putchar(char c);

int    ft_strcmp(char *s1, char *s2)
{
    while (*s1 == *s2++)
    {
        if (*s1++ == 0)
            return 0;
    }
    return (*s1 - *--s2);
}

void   ft_sort_params(int argc, char **argv)
{
    int i;
    int j;
    char *temp;

    i = 1;
    j = 2;
    while (i < argc)
    {
        while (j < argc)
        {
            if (ft_strcmp(argv[i], argv[j]) > 0)
            {
                temp = argv[i];
                argv[i] = argv[j];
                argv[j] = temp;  
            }
            j++;
        }
        j = i++ + 1;
    }
}

int    main(int argc, char **argv)
{
    int i;
    char *arg;
    
    ft_sort_params(argc, argv);
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