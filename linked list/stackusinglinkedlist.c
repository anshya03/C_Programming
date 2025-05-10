#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};

typedef struct node n;

n *getnode(int info)
{
    n *ptr = (n *)malloc(sizeof(n));
    ptr->data = info;
    ptr->link = NULL;
    return ptr;
}
n *tos = NULL;

void push(int ele)
{
    n *newnode = getnode(ele);
    if (newnode == NULL)
    {
        printf("stack is full\n");
        return;
    }
    newnode->link = tos;
    tos = newnode;
}
void pop()
{
    if (tos == NULL)
    {
        printf("stack underflow\n");
        return;
    }
    n *temp = tos;
    tos = (tos)->link;
    printf("\ndeleted element is %d\n", temp->data);
    free(temp);
}

void display()
{
    if (tos == NULL)
    {
        printf("stack is empty\n");
        return;
    }
    n *temp = tos;
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}
void main()
{

    int ele, choice, res, pos;
    while (1)
    {
        printf("\nenter the operation to be performed\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to insert\n");
            scanf("%d", &ele);
            push(ele);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        default:
            exit(0);
        }
    }
}