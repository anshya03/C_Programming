#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
} n;

n *createnode(int ele)
{
    n *ptr = (n *)malloc(sizeof(n));
    ptr->data = ele;
    ptr->link = NULL;
    return ptr;
}

// Insert at front
n *insert_front(n *last, int item)
{
    n *newnode = createnode(item);
    if (last == NULL)
    {
        last = newnode;
        last->link = last;
        return last;
    }
    newnode->link = last->link;
    last->link = newnode;
    return last;
}

// Insert at rear
n *insert_rear(n *last, int item)
{
    n *newnode = createnode(item);
    if (last == NULL)
    {
        last = newnode;
        last->link = last;
        return last;
    }
    newnode->link = last->link;
    last->link = newnode;
    last = newnode;
    return last;
}

// Delete at front
n *delete_front(n *last)
{
    if (last == NULL)
    {
        printf("No elements are present\n");
        return last;
    }
    if (last->link == last)
    {
        printf("%d is the deleted element\n", last->data);
        free(last);
        return NULL; // The list becomes empty
    }
    n *first = last->link;
    printf("%d is the deleted element\n", first->data);
    last->link = first->link;
    free(first);
    return last;
}

// Delete at rear
n *delete_rear(n *last)
{
    if (last == NULL)
    {
        printf("No elements are present\n");
        return last;
    }
    if (last->link == last)
    {
        printf("%d is the deleted element\n", last->data);
        free(last);
        return NULL; // The list becomes empty
    }
    n *temp = last->link;
    while (temp->link != last)
    {
        temp = temp->link;
    }
    printf("The element deleted is %d\n", last->data);
    temp->link = last->link;
    free(last);
    return temp; // Update last to the new rear
}

// Display elements
void display_elements(n *last)
{
    if (last == NULL)
    {
        printf("No elements are present\n");
        return;
    }
    printf("The elements are:\n");
    n *temp = last->link;
    do
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    } while (temp != last->link);
}

void main()
{
    int ele, choice;
    n *last = NULL;

    while (1)
    {
        printf("\nEnter the operation to be performed:\n");
        printf("1: Insert Front\n2: Insert Rear\n3: Delete Front\n4: Delete Rear\n5: Display Elements\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element: ");
            scanf("%d", &ele);
            last = insert_front(last, ele);
            break;
        case 2:
            printf("Enter the element: ");
            scanf("%d", &ele);
            last = insert_rear(last, ele);
            break;
        case 3:
            last = delete_front(last);
            break;
        case 4:
            last = delete_rear(last);
            break;
        case 5:
            display_elements(last);
            break;
        default:
            printf("Invalid operation\n");
            break;
        }
    }
}
