#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void rush(int x, int y);

int main()
{
    int a;
    int b;
    printf ("Enter width: ");
    scanf ("%d", &a);
    printf ("\nEnter height: ");
    scanf ("%d", &b);
    rush(a, b);
    return (0);
}   