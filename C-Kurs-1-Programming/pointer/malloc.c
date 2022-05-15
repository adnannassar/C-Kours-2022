#include <stdio.h>
#include <stdlib.h>

void strCopy(char *, const char *);
char *stringcat (const char*, const char*);
int length(const char *array);
int main()
{
    double *zeiger;
    zeiger = (double *)malloc(10 * sizeof(double));

    zeiger = (double *)malloc(5 * sizeof(double));

    // Aufgabe strcopy

    const char *original = "C macht Spass.";
    char *duplikat = (char *)malloc(sizeof(original));
    strCopy(duplikat, original);

    printf("original: %s\n", original);
    printf("duplikat: %s\n", duplikat);

    // STRING CAT TEST
    const char* str1 = "Hallo";
    const char* str2= " World";

    char* erg = stringcat(str1, str2);
    printf("Erg = %s\n", erg);
    

    return 1;
}

void strCopy(char *duplikat, const char *original)
{   
    while (*original != '\0')
    {  
        *duplikat = *original;
        original++;
        duplikat++;
    }
}

/**
 * @brief concatinate two string togather
 * @param char* str1 the first string
 * @param char* str2 the second string
 * @return char * the result of contatinating the str1 with str2
 */
char *stringcat (const char* str1, const char* str2){
    // calculatingn the length of str1 + str2
    int len = length(str1)+ length(str2);

    // allocating the memory for erg depends on len
    // len+1 is for the placeholder! --> \0
    char * erg = (char*) malloc(sizeof(len+1));
   
    // copy str1 to erg
    while(*str1){
        *erg = *str1;
        erg++;
        str1++;
    }
   // copy str2 to erg
    while(*str2){
        *erg = *str2;
        erg++;
        str2++;
    }

    // setting the placeholder for the char array
    *erg = '\0';
    // pointer restting
    erg -= len;

    return erg ;
}
    
int length(const char *array)
{
    int counter = 0;
    while (*array != '\0')
    {
        array++;
        counter++;
    }
    return counter;
}