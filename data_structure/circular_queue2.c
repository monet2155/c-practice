// Circular Queue 구현 연습 2

#include <stdio.h>

#define MAX_SIZE (6)

typedef struct
{
    int front;
    int rear;
    int data[MAX_SIZE];
} CircularQueue;

void initialize_queue(CircularQueue *queue);
int is_empty(CircularQueue *queue);
int is_full(CircularQueue *queue);
void enqueue(CircularQueue *queue, int value);
void dequeue(CircularQueue *queue);
void print_queue(CircularQueue *queue);

int main(void)
{
    CircularQueue queue;

    initialize_queue(&queue);

    print_queue(&queue);

    enqueue(&queue, 1);

    print_queue(&queue);

    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);

    print_queue(&queue);

    enqueue(&queue, 6);
    enqueue(&queue, 7);

    print_queue(&queue);

    dequeue(&queue);

    print_queue(&queue);

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);

    print_queue(&queue);

    dequeue(&queue);

    print_queue(&queue);

    enqueue(&queue, 4);
    enqueue(&queue, 5);

    dequeue(&queue);

    enqueue(&queue, 6);

    print_queue(&queue);

    return 0;
}

void initialize_queue(CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int is_empty(CircularQueue *queue)
{
    return queue->front == -1 && queue->rear == -1;
}

int is_full(CircularQueue *queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
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

void print_queue(CircularQueue *queue)
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