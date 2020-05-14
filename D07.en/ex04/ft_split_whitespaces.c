#include <stdlib.h>
#include <unistd.h>
/*
• Create a function that splits a string of characters into words.
• Separators are spaces, tabs and line breaks.
• This function returns an array where each box contains a 
character-string’s address represented by a word. The last element
of this array should be equal to 0 to emphasise the end of the array.
• There can’t be any empty strings in the array. Draw the necessary conclusions
• The given string can’t be modified.
*/

int cnt_wrds(char* str)
{
	int words;
	int newword;

	words = 0;
	newword = 1;
	while (*str)
	{
		if (*str == '\n' || *str == '\t' || *str == ' ')
			newword = 1;
		if (*str > 32 && *str < 127)
		{
			words = (newword) ? words + 1 : words;
			newword = 0;
		}
		str++;
	}
	return words;
}

int cnt_chrs(char *str, int i)
{
	int count;

	count = 0;
	while (str[i] != '\n' && str[i] != '\t' && str[i] != ' ' && str[i] != 0)
	{
		count++;
		i++;
	}
	return count;
}

char **ft_split_whitespaces(char* str)
{
	char **result;
	int i;
	int chrs;
	int strs;

	i = 0;
	strs = 0;
	if (!(result = malloc((cnt_wrds(str) + 1) * sizeof(char *))))
		return NULL;
	while (str[i])
	{
		if (str[i] > 32 && str[i] < 127)
		{
			chrs = 0;
			result[strs] = malloc((1 + cnt_chrs(str, i)) * sizeof(char));
			if (!result[strs])
				return NULL;
			while (str[i] != 10 && str[i] != 11 && str[i] != 32 && str[i] != 0)
				result[strs][chrs++] = str[i++];
			result[strs++][chrs] = '\0';
		}
		i = (str[i] == 0) ? i : i + 1;
	}
	result[strs] = (void *)0;
	return result;
}
