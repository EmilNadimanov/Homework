#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
• The purpose of this function is to find out whether two strings match.
• s1 and s2 are considered to match when s1 and s2 are identical.
• If s2 contains a star (’*’), we can replace this star by any characters string (even
empty) to make s1 and s2 identical.
• s2 may hold as many stars as you’d like.
• For example, "main.c" and "*.c" match because it is possible to replace ’*’ by
the string "main" to render those two strings identical.
• It must return 1 if s1 and s2 match, or 0 if they don’t.
*/

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
			if (s1[count++] == 0)
				break;
			continue;
		}
		return (s1[count] > s2[count]) ? 1 : -1;
	}
	return 0;
}

int match (char *s1, char *s2)
{	
	int n;
	char *flag;

	n = 1;
	while (*s1 == *s2 && *s2 != '*' && *s1 != 0)
	{
		s1++;
		s2++;
	}
	if (*s2 == '*')
	{
		while (*(s2 + n) && *(s2 + n) != '*')
			n++;
		if (n == 1 && *(s2 + n) == 0)
			return 1;
		flag = s1;
		while (*s1)
		{
			if (!ft_strncmp(s1,s2 + 1,n - 1))
				flag = s1;
			s1++;
		}
		s1 = flag;
		s2++;
	}
	else if (*s1 == *s2 && *s1 == 0)
		return 1;
	else if (*s1 != *s2)
		return 0;
	match(s1, s2);
}

int main (void)
{
	char A[50] = "123123123";
	char B[50] = "******3";
	printf ("%d\n", match(A,B));
	return 0;
}