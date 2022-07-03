#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
typedef struct Date
{
    int day, month, year;
} date;

typedef struct FridgItem
{
    char name[50];
    char detalis[50];
    date bestBefore;
} fridgItem;

fridgItem *newEntry(char name[], char details[], date bestBefore)
{
    fridgItem *item = (fridgItem *)malloc(sizeof(fridgItem));
    if (item != NULL)
    {
        stpcpy(item->name, name);
        stpcpy(item->detalis, details);
        item->bestBefore = bestBefore;
        return item;
    }
    else
    {
        return NULL;
    }
}

typedef struct NODE Node;
struct NODE
{
    fridgItem *item;
    Node *next;
};

Node *head;

bool isEmpty()
{
    return head == NULL;
}

void insert(char name[], char details[], date bestBefore)
{
    fridgItem *item = newEntry(name, details, bestBefore);
    if (item != NULL)
    {
        Node *newNode = malloc(sizeof(Node));
        newNode->item = item;
        if (isEmpty())
        {
            head = newNode;
        }
        else
        {
            Node *ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
        }
    }
    else
    {
        printf("Error by alloctaion!\n");
    }
}
bool compareDates(date date1, date date2)
{
    return date1.year < date2.year || (date1.year == date2.year && date1.month < date2.month) || (date1.year == date2.year && date1.month == date2.month && date1.day < date2.day) ||
           (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day);
}

void printSoiled(date day)
{
    if (isEmpty())
    {
        printf("Fridg is empty\n");
    }
    else
    {
        Node *ptr = head;
        int counter = 0;
        while (ptr != NULL)
        {
            if (compareDates(ptr->item->bestBefore, day))
            {
                if (counter == 0)
                {
                    printf("Abgelaufen sind:\n");
                }
                printf("Produkt %s: %s ist abgelaufen am %d.%02d.%d\n",
                       ptr->item->name, ptr->item->detalis, ptr->item->bestBefore.day, ptr->item->bestBefore.month, ptr->item->bestBefore.year);
            }
            ptr = ptr->next;
            counter++;
        }
    }
}

int main()
{
    date today = {12, 6, 2021};
    date tomorrow = {13, 6, 2021};
    date yesterday = {11, 6, 2021};
    date lastMonth = {26, 5, 2021};
    date lastYear = {26, 10, 2020};
    insert("Pizza", "liegt schon lange da", lastYear);
    insert("Senf", "mittelscharf", lastMonth);
    insert("Maultaschen", "schnelles Mittagessen", yesterday);
    insert("Marmalade", "Apfel", tomorrow);
    insert("Käse", "Emmentaler", today);

    printSoiled(today);
    return 1;
}