#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
• The aim of this function is to count the amount of times two strings match.
• When we have two or more stars, multiple string combinations can be suitable.
• nmatch calculates the total amount of combinations.
• Here are some examples :
¶ "abcbd" & "*b*" match twice : ("a","cbd") and ("abc", "d")
¶ "abc" & "a**" match 3 times : (nothing,"bc"), ("b", "c") and ("bc",
nothing)
• nmatch returns the number of combinations that match.
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

int nmatch(char *s1, char *s2)
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
		printf ("%s\n%s\n", s1, s2);
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
    return 0;
}