#include "Dic.h"
#include <stdio.h>

#define SIZE 2
int anzahl = 0;

typedef enum FLAG
{
    FULL,
    EMPTY,
    TO_BE_DELETED
} Flag;

typedef struct ENTRY
{
    int value;
    Flag flag;
} Entry;

Entry behaelter[SIZE];

int anzahlElemente()
{
    return anzahl;
}

void printDic()
{
    for (int i = 0; i < SIZE; i++)
    {
      printf("%d/", behaelter[i].value);
      if (behaelter[i].flag == FULL){
          printf("Full\t");
      }
      else if (behaelter[i].flag == EMPTY)
      {
          printf("Empty\t");
      }
      else{
          printf("To_Be_Deleted\t");
      }
    }
    printf("\n");
}
void init()
{
    for (int i = 0; i < SIZE; i++)
    {
        behaelter[i].flag = EMPTY;
    }
}

int delete (int value)
{
    if (anzahl == 0)
    {
        return 0;
    }
    else
    {
        int hashIndex = value % SIZE;
        for (int i = 0; i < SIZE; i++)
        {
            if (behaelter[hashIndex].flag != EMPTY &&
                behaelter[hashIndex].value == value)
            {
                behaelter[hashIndex].flag = TO_BE_DELETED;
                anzahl--;
                return 1;
            }
            else
            {
                hashIndex++;
                hashIndex = hashIndex % SIZE;
            }
        }
        return 0;
    }
}

bool search(int value)
{
    if (anzahl == 0)
    {
        return false;
    }
    else
    {
        int hashIndex = value % SIZE;
        for (int i = 0; i < SIZE; i++)
        {
            if (behaelter[hashIndex].flag != EMPTY &&
                behaelter[hashIndex].value == value)
            {
                return true;
            }
            else
            {
                hashIndex++;
                hashIndex = hashIndex % SIZE;
            }
        }
        return false;
    }
}

int insert(int value)
{
    if (anzahl <= SIZE)
    {
        int hashIndex = value % SIZE;

        for (int i = 0; i < SIZE; i++)
        {
            if (behaelter[hashIndex].flag != FULL)
            {
                behaelter[hashIndex].value = value;
                behaelter[hashIndex].flag = FULL;
                anzahl++;
                return 1;
            }
            else
            {
                hashIndex++;
                hashIndex = hashIndex % SIZE;
            }
        }
        return 0;
    }
    else
    {
        return 0;
    }
}