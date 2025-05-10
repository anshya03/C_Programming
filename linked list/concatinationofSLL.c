// concatinating two singly linked list
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
// insert at front
n *insertfront(n *root, int ele)
{
    n *newnode = getnode(ele);
    if (root == NULL)
    {
        return newnode;
    }
    newnode->link = root;
    root = newnode;
    return root;
}
n *concatenate(n *first, n *second)
{
    if (first == NULL)
    {
        first = second;
        return first;
    }
    n *temp = first;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = second;
    return first;
}
void display(n *root)
{
    if (root == NULL)
    {
        printf("no elements are present:");
    }
    n *temp = root;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->link;
        printf("\n");
    }
    return;
}
void main()
{
    int ele, choice;
    n *first = NULL, *second = NULL;
    while (1)
    {
        printf("enter the operation to be performed:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n enter the element in first list:");
            scanf("%d", &ele);
            first = insertfront(first, ele);
            break;
        case 2:
            printf("\n enter the element in second list:");
            scanf("%d", &ele);
            second = insertfront(second, ele);
            break;
        case 3:
            printf("the elements of first list are:");
            display(first);
            break;
        case 4:
            printf("the elements of second list are:");
            display(second);
            break;
        case 5:
            printf("concatenated list is :");
            first = concatenate(first, second);
            display(first);
            break;
        default:
            printf("invalid case");
            exit(0);
        }
    }
}
