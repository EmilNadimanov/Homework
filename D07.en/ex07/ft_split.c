#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
• Create a function that splits a string of characters depending on 
another string of characters.
• You’ll have to use each character from the string charset as a separator.
• The function returns an array where each box contains the address of a string
wrapped between two separators. The last element of that array should equal to 0
to indicate the end of the array.
• There cannot be any empty strings in your array. Draw your conclusions accord-
ingly.
• The string given as argument won’t be modifiable
*/
int	is_separator(char c, char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return 1;
	return 0;
}

int	cnt_wrds(char* str, char *charset)
{
	int words;

	words = 0;
	while (*str++)
		if ((is_separator(*str, charset) || *str == 0) &&
			is_separator(*(str - 1), charset) == 0)
			words++;
	return words;
}

int	cnt_chr(char* str, char *charset, int i)
{
	int count;

	count = 0;
	while (str[i] && is_separator(str[i++], charset) == 0)
		count++;
	return count;
}

char** fill_array(char *str, char *charset, char **rslt)
{
	int i;
	int chr;
	int word;

	word = 0;
	i = 0;
	while (str[i])
	{
		chr = 0;
		if (is_separator(str[i], charset))
			i++;
		else
		{
			rslt[word] = malloc((1 + cnt_chr(str, charset, i)) * sizeof(char));
			if (!rslt[word])
				return NULL;
			while (is_separator(str[i], charset) == 0 && str[i] != 0)
				rslt[word][chr++] = str[i++];
			rslt[word][chr] = '\0';
			word++;
		}
	}
	return rslt;
}

char **ft_split(char *str, char *charset)
{
	char **rslt;
	int words;

	words = cnt_wrds(str, charset);
	rslt = malloc((1 + words) * sizeof(*rslt));
	if (!rslt)
		return NULL;
	fill_array(str, charset, rslt);
	rslt[words] = (void *)0;
	return rslt;
}