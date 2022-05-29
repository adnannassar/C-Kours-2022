#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool leniarSearch(char *,char * array[], int);
bool strCompare(char *str1, char *str2);
bool strCompareIgnoreCase(char *str1, char *str2);
int  strLen(char *str);

int main()
{   

    // char array2d[5][5] = {"C++", "#", "Java", "css"};
    // char (*array)[5] = array2d;

    char* array[] =  {"C++", "#", "Java", "css"};
    
    
    printf("Comparing:\n");
    char *str1 = "Java";
    char *str2 = "C++";
    char *str3 = "C++";
    char *str4 = "jAvA";
    char *str5 = "Test";


    // trinary if
    printf("Comparing str1 \"%s\" with str2 \"%s\" --> ", str1, str2);
    printf(strCompare(str1, str2) ? "true\n" : "false\n");

    printf("Comparing str2 \"%s\" with str3 \"%s\" --> ", str2, str3);
    printf(strCompare(str2, str3) ? "true\n" : "false\n");

    printf("\nSearchign:\n");
    printf("Searching for str1 \"%s\" --> ", str1);
    printf(leniarSearch(str1, array, 4) ? "true\n" : "false\n");
    printf("Searching for str2 \"%s\" --> ", str2);
    printf(leniarSearch(str2, array, 4) ? "true\n" : "false\n");
    printf("Searching for str4 \"%s\" --> ", str4);
    printf(leniarSearch(str4, array, 4) ? "true\n" : "false\n");
    printf("Searching for str5 \"%s\" --> ", str5);
    printf(leniarSearch(str5, array, 4) ? "true\n" : "false\n");

    printf("\nLenth Test:\n");
    printf("Length of str1 \"%s\" --> %d\n", str1, strLen(str1));
    printf("Length of str2 \"%s\" --> %d\n", str2, strLen(str2));

    return 1;
}

bool strCompare(char *str1, char *str2)
{
    while (*str1 && *str2)
    {
        if (*str1 != *str2)
        {
            return false;
        }
        str1++;
        str2++;
    }
    return true;
}

bool strCompareIgnoreCase(char *str1, char *str2)
{
    if (strLen(str1) != strLen(str2))
    {
        return false;
    }

    while (*str1)
    {
        if ((*str1 >= 'a' && *str1 <= 'z') && (*str1 != *str2) && (*str1 - 32 != *str2))
        {
            return false;
        }

        if ((*str1 >= 'A' && *str1 <= 'Z') && (*str1 != *str2) && (*str1 + 32 != *str2))
        {
            return false;
        }

        str1++;
        str2++;
    }
    return true;
}

int strLen(char *str)
{
    int len = 0;
    while (*str)
    {
        str++;
        len++;
    }
    return len;
}

bool leniarSearch(char *word, char * array[], int len)
{
    for (int i = 0; i < len; i++)
    {                               // *(array+i)
        if (strCompareIgnoreCase(word,  array[i]))
        {
            return true;
        }
    }
    return false;
}