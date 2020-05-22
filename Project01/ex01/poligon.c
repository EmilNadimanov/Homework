#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int count;
	
	count = 0;
	if (n == 0)
		return 0;
	while (count < n)
	{
		if (s1[count] == s2[count])
		{
			count++;
			if (s1[count] == 0)
				break;
			continue;
		}
		return (s1[count] > s2[count]) ? 1 : -1;
	}
	return 0;
}

int main(void)
{
	char A[4] = "";
	char B[4] = "ar"; 
	printf("%d\n", strncmp(A,B,4));
	printf("%d\n", ft_strncmp(A,B,4));
	return 0; 
}	

