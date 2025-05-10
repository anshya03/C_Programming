#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node
{
    int data;
    struct node *link;
};
typedef struct node n;

// Global pointers for the front and rear of the queue
n *front = NULL;
n *rear = NULL;

// Function to create a new node
n *getnode(int info)
{
    n *ptr = (n *)malloc(sizeof(n));
    ptr->data = info;
    ptr->link = NULL;
    return ptr;
}

// Function to enqueue an element
void enqueue(int val)
{
    n *newnode = getnode(val);
    if (newnode == NULL)
    {
        printf("Queue is full\n");
        return;
    }

    if (rear == NULL) // Queue is empty
    {
        front = rear = newnode;
    }
    else
    {
        rear->link = newnode;
        rear = newnode;
    }
}

// Function to dequeue an element
void dequeue()
{
    if (front == NULL)
    {
        printf("\nQueue is empty\n");
        rear=NULL;
        return;
    }
    n *temp = front;
    front = front->link;
    printf("deleted element is %d\n",temp->data);
    free(temp);
}

// Function to display the queue
void display()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    n *temp = front;
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->link;
    }
}

// Main function
void main()
{
    int ele, choice;
    while (1)
    {
        printf("\nEnter the operation to be performed:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &ele);
            enqueue(ele); // Call enqueue with the element
            break;
        case 2:
            dequeue(); // Call dequeue
            break;
        case 3:
            display(); // Call display
            break;
        default:
            exit(0);
        }
    }
}