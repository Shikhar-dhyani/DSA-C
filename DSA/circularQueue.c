#include <stdio.h>
#include <stdlib.h>

typedef struct queueADT
{
    int rear;
    int front;
    int size;
    int *data;
} Queue;

Queue *create(int size)
{
    Queue *Q = (Queue *)malloc(sizeof(Queue));
    if (!Q)
        return NULL;
    Q->rear = -1;
    Q->front = -1;
    Q->size = size;
    Q->data = (int *)malloc(sizeof(int) * size);
    if (!Q->data)
        return NULL;
    return Q;
}

void Dequeue(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    else if (q->rear == q->front)
    {
        q->front = (q->front + 1) % q->size;
        q->front = -1;
        q->rear = -1;
        return;
    }
    q->front = (q->front + 1) % q->size;
    return;
}

void Display(Queue *q)
{
    if (q->front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    int s = q->front, e = q->rear;
    while (s != e)
    {
        printf("%d ", q->data[s]);
        s = (s + 1) % q->size;
    }
    printf("%d ", q->data[s]);
    return;
}

void Enqueue(int value, Queue *Q)
{
    if (Q->front == -1)
    {
        Q->front++;
    }
    else if ((Q->rear + 1) % Q->size == Q->front)
    {
        printf("Queue is full\n");
        return;
    }
    Q->rear = (Q->rear + 1) % Q->size;
    Q->data[Q->rear] = value;
    return;
}
int main()
{
    Queue *Q = create(5);
    while (1)
    {
        printf("Enter your Choice : 1.Enqueue 2.Dequeue 3.IsEmpty 4.Front 5.Exit \n");
        int choice, value;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data : ");
            scanf("%d", &value);
            Enqueue(value, Q);
            break;

        case 2:
            Dequeue(Q);
            break;

        case 5:
            Display(Q);
            return 0;
        }
    }

    return 0;
}