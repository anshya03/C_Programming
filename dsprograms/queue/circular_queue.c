#include <stdio.h>
#include <stdlib.h>
#define max 30
struct cqueue
{
    int arr[max];
    int front, rear;
};
typedef struct cqueue q1;
int isfull(q1 q)
{
    if ((q.rear + 1) % max == q.front)
        return 1;
    return -1;
}
int isempty(q1 q)
{
    if ((q.front == -1) && (q.rear == -1))
    {
        return 2;
    }
    return -2;
}
void cenqueue(q1 *q, int ele)
{
    if (isfull(*q) == 1)
    {
        printf("circular queue is full");
        return;
    }
    if (isempty(*q) == 2)
    {
        q->front = 0;
        q->rear++;
        q->arr[q->rear] = ele;
        return;
    }
    q->rear = (q->rear + 1) % max;
    q->arr[q->rear] = ele;
}
int dequeue(q1 *q)
{
    if (isempty(*q) == 2)
    {
        printf("circular queue is empty");
        return 3;
    }
    if (q->rear == q->front)
    {
        int item = q->arr[q->front];
        q->front = -1;
        q->rear = -1;
        return item;
    }
    int item = q->arr[q->front];
    q->front = (q->front + 1) % max;
    return item;
}
void display(q1 q)
{
    if (isempty(q) == 2)
    {
        printf("no elements in circular queue");
        return;
    }
    printf("the elements of the circular queue are:");
    for (int i = q.front; i != (q.rear + 1) % max; i = (i + 1) % max)
    {
        printf("%d\n", q.arr[i]);
    }
}
void main()
{
    q1 q;
    q.front = -1, q.rear = -1;
    int choice, ele, item;
    while (1)
    {
        printf("enter the operation to be performed:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the number to be inserted:");
            scanf("%d", &ele);
            cenqueue(&q, ele);
            break;
        case 2:
            item = dequeue(&q);
            printf("the element removed is %d", item);
            break;
        case 3:
            display(q);
            break;
        default:
            printf("invalid operation:");
            exit(0);
        }
    }
}