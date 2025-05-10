#include <stdio.h>
#include <stdlib.h>
#define max 10
struct queue
{
    int items[max];
    int front, rear;
};
typedef struct queue q;
int isFull(q q1)
{
    if (q1.rear == (max - 1))
        return 1;
    return 0;
}
int isEmpty(q q1)
{
    if (q1.front > q1.rear)
        return 1;
    return 0;
}
void enqueue(q *q1, int ele)
{
    if (isFull(*q1))
    {
        printf("queue is full\n");
        return;
    }
    q1->rear++;
    q1->items[q1->rear] = ele;
}
int dequeue(q *q1)
{
    if (isEmpty(*q1))
    {
        printf("queue is empty\n");
        return 999;
    }
    return q1->items[q1->front++];
}
void display(q q1)
{
    int i;
    if (isEmpty(q1))
    {
        printf("The queue is empty\n");
        return;
    }
    printf("the element of queue are\n");
    for (i = q1.front; i <= q1.rear; i++)
        printf("%d\n", q1.items[i]);
}

void main()
{
    q q1;
    int ele, choice;
    q1.front = 0;
    q1.rear = -1;
    while (1)
    {
        printf("enter the operation to be performed\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the elements to be enqueue\n");
            scanf("%d", &ele);
            enqueue(&q1, ele);
            break;
        case 2:
            ele = dequeue(&q1);
            if (ele != 999)
                printf("%d is dequeued element\n", ele);
            break;
        case 3:
            display(q1);
        default:
            exit(0);
        }
    }
}