/*
Q5. Write a C/C++ program to implement dequeue(doubly endded
queue) data structure using array.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX 100 // Maximum size of the deque

typedef struct Deque
{
    int arr[MAX];
    int front, rear;
} Deque;

// Initialize the deque
void initDeque(Deque *dq)
{
    dq->front = -1;
    dq->rear = -1;
}

// Check if the deque is empty
int isEmpty(Deque *dq)
{
    return dq->front == -1;
}

// Check if the deque is full
int isFull(Deque *dq)
{
    return (dq->rear + 1) % MAX == dq->front;
}

// Insert an element at the front of the deque
void insertFront(Deque *dq, int x)
{
    if (isFull(dq))
    {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->front = (dq->front - 1 + MAX) % MAX;
    }
    dq->arr[dq->front] = x;
}

// Insert an element at the rear of the deque
void insertRear(Deque *dq, int x)
{
    if (isFull(dq))
    {
        printf("Deque is full\n");
        return;
    }
    if (isEmpty(dq))
    {
        dq->front = dq->rear = 0;
    }
    else
    {
        dq->rear = (dq->rear + 1) % MAX;
    }
    dq->arr[dq->rear] = x;
}

// Delete an element from the front of the deque
void deleteFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    if (dq->front == dq->rear)
    { // Only one element
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->front = (dq->front + 1) % MAX;
    }
}

// Delete an element from the rear of the deque
void deleteRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    if (dq->front == dq->rear)
    { // Only one element
        dq->front = dq->rear = -1;
    }
    else
    {
        dq->rear = (dq->rear - 1 + MAX) % MAX;
    }
}

// Get the front element of the deque
int getFront(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->front];
}

// Get the rear element of the deque
int getRear(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return -1;
    }
    return dq->arr[dq->rear];
}

// Display the elements of the deque
void display(Deque *dq)
{
    if (isEmpty(dq))
    {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    for (int i = dq->front; i != dq->rear; i = (i + 1) % MAX)
    {
        printf("%d ", dq->arr[i]);
    }
    printf("%d\n", dq->arr[dq->rear]); // Print the rear element
}

int main()
{
    Deque dq;
    initDeque(&dq);

    insertRear(&dq, 10);
    insertRear(&dq, 20);
    insertFront(&dq, 5);
    insertFront(&dq, 2);

    display(&dq);

    printf("Front element: %d\n", getFront(&dq));
    printf("Rear element: %d\n", getRear(&dq));

    deleteFront(&dq);
    display(&dq);

    deleteRear(&dq);
    display(&dq);

    return 0;
}
