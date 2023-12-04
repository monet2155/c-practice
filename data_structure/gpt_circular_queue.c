#include <stdio.h>

#define MAX_SIZE (6)

typedef struct
{
    int front, rear;
    int data[MAX_SIZE];
} CircularQueue;

void initializeQueue(CircularQueue *queue);
int isEmpty(CircularQueue *queue);
int isFull(CircularQueue *queue);
void enqueue(CircularQueue *queue, int value);
void dequeue(CircularQueue *queue);
void displayQueue(CircularQueue *queue);

int main(void)
{
    CircularQueue queue;
    initializeQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);

    displayQueue(&queue);

    dequeue(&queue);

    displayQueue(&queue);

    enqueue(&queue, 5);
    enqueue(&queue, 6);

    displayQueue(&queue);

    return 0;
}

void initializeQueue(CircularQueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

int isEmpty(CircularQueue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(CircularQueue *queue)
{
    /**
     * rear + 1이 6일때 0 == front
     * front가 0이면 0부터 배열의 맨 마지막까지 차있다(rear가 마지막을 가리키고 있으니)
     */
    return ((queue->rear + 1) % MAX_SIZE == queue->front);
}

void enqueue(CircularQueue *queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }

    if (isEmpty(queue))
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
    if (isEmpty(queue))
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

void displayQueue(CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue: ");
    int i = queue->front;
    /**
     * front가 0이고 rear가 4일때
     * i = (i+1) % MAX_SIZE는 한칸씩 뒤로 보내는 동작 (MAX를 넘으면 다시 0으로)
     * 5 != (5) % MAX_SIZE
     * 조건문 실패
     */
    do
    {
        printf("%d ", queue->data[i]);
        i = (i + 1) % MAX_SIZE;
    } while (i != (queue->rear + 1) % MAX_SIZE);
    printf("\n");
}