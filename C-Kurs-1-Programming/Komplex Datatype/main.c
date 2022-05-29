#include <stdio.h>
#include <stdlib.h>

typedef char *string;

// typedef struct CAR Car;

typedef enum GENDER Gender;

enum GENDER
{
    feiblich,
    mänlich
};

typedef struct PERSON
{
    // Attributes
    string name;
    int age;
    Gender gender;
} Person;

int main()
{

    Person p;
    p.name = "Ruaa";
    p.gender = feiblich;

    printf("%s ist ", p.name);
    if (p.gender == 0)
    {
        printf("feiblich");
    }
    else
    {
        printf("mänlcih");
    }

    return 1;
}
