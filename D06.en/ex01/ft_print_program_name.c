#include <stdlib.h>
#include <unistd.h>

void ft_putchar(char c);

int main(int argc, char **argv)
{
    char *prog;

    prog = *argv;
    while (*prog)
        ft_putchar(*prog++);
    ft_putchar('\n');
    return 0;
}
