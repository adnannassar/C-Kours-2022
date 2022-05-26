#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool leniarSearch(char *, char **, int);

int main()
{
    //TODO

    // char **array = {"C++", "#", "Java", "css"};
    //printf("%d ", leniarSearch("Java", array, 4));

    return 1;
}

//TODO
bool leniarSearch(char *word, char **array, int len)
{
    for (int i = 0; i < len; i++)
    {

        if (word == array)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    return true;
}