#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct QueueAdt
{
    int front;
    int rear;
    int cap;
    int *queue;
};

struct QueueAdt *createQueue(int capacity)
{
    struct QueueAdt *temp = (struct QueueAdt *)malloc(sizeof(struct QueueAdt));
    temp->front = -1;
    temp->rear = -1;
    temp->cap = capacity;
    temp->queue = (int *)malloc(sizeof(int) * capacity);
    return temp;
}

bool isFull(struct QueueAdt *Q)
{
    if (Q->rear == Q->cap - 1)
        return 1;
    return 0;
}
void Enqueue(int data, struct QueueAdt *Q)
{
    if (isFull(Q))
    {
        Q->queue = (int *)realloc(Q->queue, Q->cap + 5);
        Q->cap = Q->cap + 5;
    }
    if (Q->rear == -1)
        Q->front = 0;

    Q->queue[++Q->rear] = data;

    return;
}

bool isEmpty(struct QueueAdt *Q)
{
    if (Q->rear < Q->front)
        return 1;
    return 0;
}

void Dequeue(struct QueueAdt *Q)
{
    if (isEmpty(Q))
        printf("---Queue is Empty ---\n");
    else
        printf("Dequeued Element is %d \n", Q->queue[Q->front++]);

    return;
}

void Display(struct QueueAdt *Q)
{
    if (isEmpty(Q))
    {
        printf("---Queue is Empty ---\n");
        return;
    }

    int front = Q->front;

    while (front != Q->rear)
        printf("%d ", Q->queue[front++]);

    printf("%d", front);
    printf("\n");
    return;
}

void Front(struct QueueAdt *Q)
{
    if (isEmpty(Q))
        printf("---Queue is Empty ---\n");
    else
        printf(" 1st element of Queue is %d\n", Q->queue[Q->front]);
    return;
}

int main()
{
    struct QueueAdt *Q = createQueue(5);
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

        case 3:
            value = isEmpty(Q);
            if (value)
                printf("---Queue is Empty ---\n");
            else
                printf("---Queue is not Empty ---\n");
            break;

        case 4:
            Front(Q);
            break;

        case 5:
            Display(Q);
            return 0;
        }
    }
    return 0;
}
