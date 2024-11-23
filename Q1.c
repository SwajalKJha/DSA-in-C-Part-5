/*
Q1. Write a C/C++ program to implement single circular linked list
with below metioned functionality.
a) insertAtEnd b) insertAtBeg c) insertAtPos
d) display e) listNodeCount f) deleteFromEnd
g) deleteFromBeg h) deleteFromPos
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct patient
{
    char name[20];
    int age;
    int ward_num;
};

struct node
{
    struct patient p;
    struct node *next;
};

void addAtBeg(struct node **);
void addAtEnd(struct node **);
void addAtPos(struct node **, int);
void deleteFromBeg(struct node **);
void deleteFromEnd(struct node **);
void deletePos(struct node **, int);
void deleteElement(struct node **);
void freeNodes(struct node **);
void countNodes(struct node **);
void display(struct node *);

int main()
{
    struct node *head = NULL;
    int choice, pos;

    while (1)
    {
        printf("*************************\n");
        printf(" 1. Add at Beginning\n 2. Add at End\n 3. Add at Position\n 4. Delete from Beginning\n 5. Delete from End\n 6. Delete a Position\n 7. Delete by Element\n 8. Free all Nodes\n 9. Count Nodes\n 10. Display\n 11. Quit\n");
        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addAtBeg(&head);
            break;
        case 2:
            addAtEnd(&head);
            break;
        case 3:
            printf("Enter Position to Add: ");
            scanf("%d", &pos);
            addAtPos(&head, pos);
            break;
        case 4:
            deleteFromBeg(&head);
            break;
        case 5:
            deleteFromEnd(&head);
            break;
        case 6:
            printf("Enter Position to Delete: ");
            scanf("%d", &pos);
            deletePos(&head, pos);
            break;
        case 7:
            deleteElement(&head);
            break;
        case 8:
            freeNodes(&head);
            break;
        case 9:
            countNodes(&head);
            break;
        case 10:
            display(head);
            break;
        case 11:
            printf("Quitting...\n");
            return 0;
        default:
            printf("Enter a Valid Choice\n");
            break;
        }
    }
    return 0;
}

void addAtBeg(struct node **q)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Patient's Name: ");
    scanf("%19s", temp->p.name);
    printf("Enter Patient's Age: ");
    scanf("%d", &temp->p.age);
    printf("Enter Patient's Ward Number: ");
    scanf("%d", &temp->p.ward_num);

    if (*q == NULL)
    {
        temp->next = temp; // Point to itself
    }
    else
    {
        struct node *last = *q;
        while (last->next != *q)
        { // Find last node
            last = last->next;
        }
        last->next = temp; // Last node points to new node
        temp->next = *q;   // New node points to head
    }
    *q = temp; // Update head to new node
}

void addAtEnd(struct node **q)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Patient's Name: ");
    scanf("%19s", temp->p.name);
    printf("Enter Patient's Age: ");
    scanf("%d", &temp->p.age);
    printf("Enter Patient's Ward Number: ");
    scanf("%d", &temp->p.ward_num);

    if (*q == NULL)
    {
        temp->next = temp; // Point to itself
    }
    else
    {
        struct node *last = *q;
        while (last->next != *q)
        { // Find last node
            last = last->next;
        }
        last->next = temp; // Last node points to new node
        temp->next = *q;   // New node points to head
    }
}

void addAtPos(struct node **q, int pos)
{
    if (pos < 1)
    {
        printf("Invalid Position!\n");
        return;
    }
    if (pos == 1 || *q == NULL)
    {
        addAtBeg(q);
        return;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL)
    {
        printf("Memory Allocation Failed!\n");
        return;
    }
    printf("Enter Patient's Name: ");
    scanf("%19s", temp->p.name);
    printf("Enter Patient's Age: ");
    scanf("%d", &temp->p.age);
    printf("Enter Patient's Ward Number: ");
    scanf("%d", &temp->p.ward_num);

    struct node *current = *q;
    int counter = 1;
    while (current->next != *q && counter < pos - 1)
    {
        current = current->next;
        counter++;
    }
    temp->next = current->next; // Link new node to the next node
    current->next = temp;       // Link current node to new node

    if (temp->next == *q)
    {                    // If adding at the end
        temp->next = *q; // Ensure new node points to head
    }
}

void deleteFromBeg(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to Delete\n");
        return;
    }
    struct node *temp = *q;
    if (temp->next == *q)
    { // Only one node
        free(temp);
        *q = NULL;
    }
    else
    {
        struct node *last = *q;
        while (last->next != *q)
        {
            last = last->next;
        }
        last->next = temp->next; // Last node points to new head
        *q = temp->next;         // Update head
        free(temp);
    }
    printf("Node Deleted from the List\n");
}

void deleteFromEnd(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to Delete\n");
        return;
    }
    struct node *current = *q;
    struct node *previous = NULL;

    while (current->next != *q)
    {
        previous = current;
        current = current->next;
    }
    if (previous == NULL)
    { // Only one node
        free(current);
        *q = NULL;
    }
    else
    {
        previous->next = *q; // Previous node points to head
        free(current);
    }
    printf("Node Deleted from the List\n");
}

void deletePos(struct node **q, int pos)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to Delete\n");
        return;
    }

    struct node *current = *q;
    struct node *previous = NULL;

    if (pos == 1)
    {
        deleteFromBeg(q);
        return;
    }

    int counter = 1;
    while (current->next != *q && counter < pos)
    {
        previous = current;
        current = current->next;
        counter++;
    }

    if (counter < pos)
    {
        printf("Position %d does not Exist\n", pos);
        return;
    }

    previous->next = current->next; // Link previous to next node
    if (current == *q)
    {                        // If deleting the head
        *q = previous->next; // Update head
    }
    free(current);
    printf("Node Deleted from the List\n");
}

void deleteElement(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to Delete\n");
        return;
    }

    char name[20];
    printf("Enter Patient's Name to Delete Record: ");
    scanf("%19s", name);

    struct node *current = *q;
    struct node *previous = NULL;

    do
    {
        if (strcmp(current->p.name, name) == 0)
        {
            if (previous == NULL)
            { // Deleting head
                deleteFromBeg(q);
            }
            else
            {
                previous->next = current->next; // Link previous to next
                free(current);
                printf("Node Deleted from the List\n");
                return;
            }
        }
        previous = current;
        current = current->next;
    } while (current != *q);

    printf("Record does not Exist\n");
}

void freeNodes(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to delete\n");
        return;
    }

    struct node *current = *q;
    struct node *temp;

    do
    {
        temp = current;
        current = current->next;
        free(temp);
    } while (current != *q);

    *q = NULL; // Reset head to
    printf("All Nodes Deleted from the List\n");
}

void countNodes(struct node **q)
{
    if (*q == NULL)
    {
        printf("List is Empty, nothing to Count\n");
        return;
    }

    struct node *current = *q;
    int counter = 0;

    do
    {
        counter++;
        current = current->next;
    } while (current != *q);

    printf("Number of Nodes are: %d\n", counter);
}

void display(struct node *q)
{
    if (q == NULL)
    {
        printf("The List is Empty\n");
        return;
    }

    struct node *current = q;

    do
    {
        printf("---> Name: %s, Age: %d, Ward Number: %d ", current->p.name, current->p.age, current->p.ward_num);
        current = current->next;
    } while (current != q);

    printf("\n");
}
