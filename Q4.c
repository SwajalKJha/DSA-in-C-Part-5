/*
Q4. Write a C/C++ program to implement priority queue data
structure using array.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int priority;
    struct Node *next;
} Node;

void createNode(Node **newNode, int data, int priority);
void enqueue(Node **head, int data, int priority);
void dequeue(Node **head);
void display(Node *head);

int main()
{
    Node *head = NULL;
    int choice, data, priority;

    do
    {
        printf("\nMenu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data and priority: ");
            scanf("%d %d", &data, &priority);
            enqueue(&head, data, priority);
            break;
        case 2:
            dequeue(&head);
            break;
        case 3:
            display(head);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    // Free the remaining nodes if any
    while (head != NULL)
    {
        dequeue(&head);
    }

    return 0;
}

void createNode(Node **newNode, int data, int priority)
{
    *newNode = (Node *)malloc(sizeof(Node));
    (*newNode)->data = data;
    (*newNode)->priority = priority;
    (*newNode)->next = NULL;
}

void enqueue(Node **head, int data, int priority)
{
    Node *newNode;
    createNode(&newNode, data, priority);

    if (*head == NULL || (*head)->priority < priority)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *current = *head;
        while (current->next != NULL && current->next->priority >= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void dequeue(Node **head)
{
    if (*head == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    printf("Dequeued: Data = %d, Priority = %d\n", temp->data, temp->priority);
    free(temp);
}

void display(Node *head)
{
    if (head == NULL)
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Priority Queue:\n");
    while (head != NULL)
    {
        printf("Data: %d, Priority: %d\n", head->data, head->priority);
        head = head->next;
    }
}
