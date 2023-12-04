#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE (5)

typedef struct
{
    int front;
    int rear;
    int data[MAX_SIZE];
} CircularQueue;

void initialize_queue(CircularQueue *queue);
bool is_empty(CircularQueue *queue);
bool is_full(CircularQueue *queue);
void enqueue(CircularQueue *queue, int value);
void dequeue(CircularQueue *queue);
void display_queue(CircularQueue *queue);

int main(void)
{
    CircularQueue queue;

    initialize_queue(&queue);
    display_queue(&queue);

    enqueue(&queue, 1);

    display_queue(&queue);

    dequeue(&queue);

    display_queue(&queue);

    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);

    display_queue(&queue);

    dequeue(&queue);

    display_queue(&queue);

    dequeue(&queue);
    dequeue(&queue);

    display_queue(&queue);

    enqueue(&queue, 4);
    enqueue(&queue, 5);
    enqueue(&queue, 6);

    enqueue(&queue, 7);
    enqueue(&queue, 8);

    display_queue(&queue);

    dequeue(&queue);
    dequeue(&queue);

    display_queue(&queue);

    enqueue(&queue, 9);
    enqueue(&queue, 10);
    display_queue(&queue);

    return 0;
}

void initialize_queue(CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool is_empty(CircularQueue *queue)
{
    return queue->front == -1 && queue->rear == -1;
}

bool is_full(CircularQueue *queue)
{
    // return (queue->front + queue->rear + 1) == MAX_SIZE;
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(CircularQueue *queue, int value)
{
    if (is_full(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (is_empty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }

    queue->data[queue->rear] = value;
}

void dequeue(CircularQueue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }

    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
}

void display_queue(CircularQueue *queue)
{
    if (is_empty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    int i = queue->front;

    printf("Queue : ");
    do
    {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);

    printf("\n");
}