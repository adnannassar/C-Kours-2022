#include "LinkedList.h"
#include "stdlib.h"
#include <stdio.h>

typedef struct NODE Node;

struct NODE
{
    int value;
    Node *next;
};

Node *head;

void add(int value)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode != 0)
    {
        newNode->value = value;
        
        if (isEmpty())
        {
            head = newNode;
        }
        else
        {
            Node *poniter = head;
            while (poniter->next != NULL)
            {
                poniter = poniter->next;
            }
            poniter->next = newNode;
        }
    }
    else
    {
        printf("Error!\n");
    }
}
bool isEmpty()
{
    return head == NULL;
}
bool search()
{
    return false;
}
void delete ()
{
}
void print()
{
    if(isEmpty()){
        printf("List is empty\n");
    }else{
        Node *poniter = head;
        while (poniter != NULL)
        {
            printf("%d ", poniter->value);
            poniter = poniter->next;
        }
        printf("\n");
    }
  
}