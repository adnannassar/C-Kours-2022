#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("The size of unsigned short %lu\n", sizeof(unsigned short));
    printf("The size of signed short %lu\n", sizeof(signed short));
    printf("The size of unsigned int %lu\n", sizeof(unsigned int));
    printf("The size of signed int %lu\n", sizeof(signed int));
    printf("The size of unsigned long %lu\n", sizeof(unsigned long));
    printf("The size of signed long %lu\n", sizeof(signed long));
    printf("The size of float %lu\n", sizeof(float));
    printf("The size of double %lu\n", sizeof(double));
    printf("The size of char %lu\n", sizeof(char));

    printf("----------------------------\n");
    const char a = '@';

    printf("%c\n", a);
    printf("%d\n", a);

    printf("----------------------------\n");

    long xx = 10;
    int yy = (int)xx; // explizite type konvertierung

    printf("Calculator\n");
    // read the first number from user
    printf("Enter the nr1: ");
    double nr1;
    scanf("%lf", &nr1);

    // read the operation from user
    printf("\nSelect the opertaion: + - * /: ");
    char op;
    scanf(" %c", &op);

    // read the second number from user
    printf("\nEnter the nr2: ");
    double nr2;
    scanf("%lf", &nr2);

    // calculate the result using the switch
    double result;
    switch (op)
    {
    case '+':
        result = nr1 + nr2;
        break;
    case '-':
        result = nr1 - nr2;
        break;
    case '*':
        result = nr1 * nr2;
        break;
    case '/':
        result = nr1 / nr2;
        break;
    default:
        printf("ERROR!\n");
    }

    // the reuslt of 2 * 2.7 = 5.14
    printf("The reuslt of %.2lf %c %.2lf = %.2lf\n", nr1, op, nr2, result);

    // 1. for
    printf("For:      ");
    for (int x = 1; x <= 10; ++x)
    {
        if (x % 2 != 0)
        {
            printf("A ");
        }
       
        else
        {
            printf("%d ", x);
        }
    }

    // 2. while
    printf("\nWhile:    ");
    int x = 1;
    while (x <= 10)
    {
        printf("%d ", x);
        x++;
    }
    // 3. do while
    printf("\nDo While: ");
    int i = 1;
    do
    {
        printf("%d ", i);
        i++;
    } while (i <= 10);
    
    

    // geschfeifte klammer {}
    // eckige klammer []
    // runde klammer ()
    // spitze klammer <>
    // + - * / % && || += ++ -= -- *= /* ! = != < > >= <=
    // true 1, false 0
    

    return 1;
}
