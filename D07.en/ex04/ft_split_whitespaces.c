#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
/*
• Create a function that splits a string of characters into words.
• Separators are spaces, tabs and line breaks.
• This function returns an array where each box contains a character-string’s address
represented by a word. The last element of this array should be equal to 0 to
emphasise the end of the array.
• There can’t be any empty strings in your array. Draw the necessary conclusions.
• The given string can’t be modified.
*/

int count_words(char* str)
{
    int strs;
    int newword;

    strs = 0;
    newword = 0;
    while (*str)
    {
        if (*str == '\n' || *str  == '\t' || *str == ' ')
            newword = 1;
        if (*str > 32 && *str++ < 127) 
        {
            if (newword) 
                strs++;
            newword = 0;
        }
    }
    return strs;
}

void input_words(char *str, char ***result)
{
    
}

void input_words(char *str, char ***result)
{
    int chrs;
    int i;
    int newword;

    i = -1;
    newword = 1;
    while (*str)
    {
        if (*str == '\n' || *str  == '\t' || *str == ' ')
            newword = 1;
        if (*str > 32 && *str++ < 127) 
        {
            if (newword)
            {
                chrs = 0;
                i++;
            }
            *result[i][chrs] = *str;
            chrs++;
            newword = 0;
        }
    }
    *result[i][chrs] = '\0';
}

char** ft_split_whitespaces(char* str)
{
    char **result;
    char *word;
    int strs;
     int chrs;    

    strs = 0;
    strs = count_words(str);
    result = malloc((strs + 1) * sizeof(*result));
    count_chars(ste, &result);
    input_words(str, &result);

}

int main()
{

}
