#include "Dic.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 3
int anzahl = 0;

typedef struct NODE Node;

struct NODE
{
    int value;
    Node *next;
};

Node *array[SIZE];

int insert(int value)
{

    int hashIndex = hash(value);
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode != NULL)
    {
        newNode->value = value;
        newNode->next = array[hashIndex];
        array[hashIndex] = newNode;

        anzahl++;
        return 1;
    }
    else
    {
        return 0;
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
        int hashIndex = hash(value);
        if (array[hashIndex] != NULL)
        {
            Node *ptr = array[hashIndex];
            Node *before_ptr = NULL;
            while (ptr != NULL)
            {
                if (ptr->value == value)
                {
                    if (before_ptr == NULL)
                    {
                        array[hashIndex] = array[hashIndex]->next;
                    }
                    else
                    {
                        before_ptr->next = ptr->next;
                    }
                    free(ptr);
                    anzahl--;
                    return 1;
                }
                else
                {
                    before_ptr = ptr;
                    ptr = ptr->next;
                }
            }
        }
        else
        {
            return 0;
        }
        return 0;
    }
}
bool search(int value)
{
    int hashIndex = hash(value);
    if (array[hashIndex] != NULL)
    {
        Node *ptr = array[hashIndex];
        while (ptr != NULL)
        {
            if (ptr->value == value)
            {
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }
    else
    {
        return false;
    }
}

int anzahlElemente()
{
    return anzahl;
}

void printDic()
{
    for (int i = 0; i < SIZE; i++)
    {
        if (array[i] != NULL)
        {
            Node *ptr = array[i];
            while (ptr->next != NULL)
            {
                printf("%d\t->\t", ptr->value);
                ptr = ptr->next;
            }
            printf("%d\n", ptr->value);
        }
    }
}

void sortColums()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE - 1; j++)
        {
            if (array[j]->value > array[j + 1]->value)
            {
                swap(j, j + 1);
            }
        }
    }
}

void sortRows()
{
    // TODO
    /*
    quelle:
    -30     ->      3       ->      -15     ->      9       ->      6
    25      ->      112     ->      100     ->      10      ->      1
    2       ->      14      ->      8       ->      5

    erwartet:
    -30     ->      -15       ->      3     ->      6       ->      9
    1       ->      10        ->      25    ->      100     ->      112
    2       ->      5         ->      8     ->      14
    */
}

void swap(int i, int j)
{
    Node *temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int hash(int value)
{
    return ((value % SIZE) + SIZE) % SIZE;
}