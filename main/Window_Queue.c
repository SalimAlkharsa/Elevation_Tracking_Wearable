#include <stdio.h>
#include <stdlib.h>
#include "Window.c"

// Define the maximum capacity of the queue, this value is arbitrary
#define MAX_CAPACITY 50

// Define the Node structure for the queue
// Basically the Node has a Window data and a pointer to the next Node
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

    // Allocate memory for the new node
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Error: Failed to allocate memory for the new node.\n");
        exit(EXIT_FAILURE);
    }

    // Assign data to the new node
    newNode->data = window;
    newNode->next = NULL;

    // Handle the edge case of an empty queue, where the front and rear pointers are the same
    if (isEmpty(queue))
    {
        queue->front = newNode;
        queue->rear = newNode;
    }
    // Otherwise add the new node to the rear of the queue and update the rear pointer
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

    // Get the front node and its data
    Node *frontNode = queue->front;
    Window frontWindow = frontNode->data;

    // Update the front pointer to the next node
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

// Function to print the queue
void printQueue(WindowQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    // Iterate through the queue and print the data of each node
    Node *currentNode = queue->front;

    // Iteration logic to print each window
    printf("Queue contents:\n");
    while (currentNode != NULL)
    {
        Window currentWindow = currentNode->data;

        printf("Window observations:\n");
        printf("Observation count: %d\n", currentWindow.observationCount);
        // Iteration logic to print each observation (so that is component of the window (should be 1 any time it is not 1 it is a bug in the code somewhere else))
        for (int i = 0; i < currentWindow.observationCount; ++i)
        {
            // Exctract the current observation's data and print it
            Observation currentObservation = currentWindow.observations[i];
            printf("Observation %d: Pa=%.2f, Z_rot=%.2f, Z_acc=%.2f, Y_acc=%.2f\n",
                   i + 1, currentObservation.Pa, currentObservation.Z_rot,
                   currentObservation.Z_acc, currentObservation.Y_acc);
            Metrics currentMetrics = currentWindow.metrics;
            printf("Window metrics:\n");
            printf("Pa_roc: %.2f\n", currentMetrics.Pa_roc);
            printf("Z_rot_max_min: %.2f\n", currentMetrics.Z_rot_max_min);
            printf("Z_g_max: %.2f\n", currentMetrics.Z_g_max);
            printf("Z_g_min: %.2f\n", currentMetrics.Z_g_min);
            printf("Y_g_kurtosis: %.2f\n", currentMetrics.Y_g_kurtosis);
        }
        currentNode = currentNode->next;
    }
}