#include <stdio.h>
#include <stdlib.h>
#include "Window.c"

// Define the maximum capacity of the queue
#define MAX_CAPACITY 50

// Define the Node structure for the queue
typedef struct Node
{
    Window data;
    struct Node *next;
} Node;

// Define the Queue structure
typedef struct
{
    Node *front;
    Node *rear;
    int size;
    int capacity;
} WindowQueue;

// Function to initialize the queue
WindowQueue *initializeQueue()
{
    WindowQueue *queue = (WindowQueue *)malloc(sizeof(WindowQueue));
    if (queue == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for the queue.\n");
        exit(EXIT_FAILURE);
    }

    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
    queue->capacity = MAX_CAPACITY;

    return queue;
}

// Function to check if the queue is empty
int isEmpty(WindowQueue *queue)
{
    return queue->size == 0;
}

// Function to check if the queue is full
int isFull(WindowQueue *queue)
{
    return queue->size == queue->capacity;
}

// Function to enqueue a Window into the queue
void enqueue(WindowQueue *queue, Window window)
{
    if (isFull(queue))
    {
        fprintf(stderr, "Error: Queue is full. Cannot enqueue.\n");
        exit(EXIT_FAILURE);
    }

    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for the new node.\n");
        exit(EXIT_FAILURE);
    }

    newNode->data = window;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else
    {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    queue->size++;
}

// Function to dequeue a Window from the queue
Window dequeue(WindowQueue *queue)
{
    if (isEmpty(queue))
    {
        fprintf(stderr, "Error: Queue is empty. Cannot dequeue.\n");
        exit(EXIT_FAILURE);
    }

    Node *frontNode = queue->front;
    Window frontWindow = frontNode->data;

    queue->front = frontNode->next;
    free(frontNode);

    queue->size--;

    return frontWindow;
}

// Function to free the memory allocated for the queue
void destroyQueue(WindowQueue *queue)
{
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }

    free(queue);
}
