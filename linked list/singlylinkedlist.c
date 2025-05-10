#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
} n;
n *getnode(int info)
{
    n *ptr;
    ptr = (n *)malloc(sizeof(n));
    ptr->data = info;
    ptr->link = NULL;
    return ptr;
}
n *insertfront(n *root, int data)
{
    n *newnode;
    newnode = getnode(data);
    if (root == NULL)
    {
        root = newnode;
        return root;
    }

    newnode->link = root;
    root = newnode;
    return root;
}
n *deletefront(n *root)
{
    n *temp;
    if (root == NULL)
    {
        printf("\nno elements");
        return NULL;
    }
    temp = root;
    root = root->link;
    printf("deleted element is %d", temp->data);
    free(temp);
    return root;
}
n *insertrear(n *root, int ele)
{
    n *newnode;
    n *temp;
    newnode = getnode(ele);
    if (root == NULL)
    {
        return newnode;
    }
    temp = root;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
    return root;
}
n *deleterear(n *root)
{
    n *temp, *prev;
    prev = NULL;
    if (root == NULL)
    {
        printf("no elements are present\n");
        return NULL;
    }

    if (root->link == NULL)
    {
        printf("deleted element is %d", root->data);
        free(root);
        return NULL;
    }
    temp = root;
    while (temp->link != NULL)
    {
        prev = temp;
        temp = temp->link;
    }
    prev->link = NULL;
    printf("deleted elment is %d\n", temp->data);
    free(temp);
    return root;
}
int search(n *root, int element)
{
    int pos = 0;
    n *temp = root;
    if (root == NULL)
    {
        printf("no elements\n");
        return -1;
    }
    while (temp != NULL)
    {
        if (temp->data == element)
        {
            printf("the element is found at position %d\n", pos);
            return pos;
        }
        temp = temp->link;
        pos++;
    }
    printf("element not found\n");
    return -1;
}
void display(n *root)
{
    n *temp;
    temp = root;
    if (root == NULL)
    {
        printf("\nthere are no elements\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->link;
    }
}
void main()
{
    int choice, data, ele, element, pos;
    n *root = NULL;
    while (1)
    {
        printf("enter the operation to be performed:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nenter element to be inserted at front:");
            scanf("%d", &data);
            printf("element inserted at front is %d\n", data); // insert at front
            root = insertfront(root, data);
            break;
        case 2:
            // delete front
            root = deletefront(root);
            break;
        case 3:
            printf("enter the number to be inserted at rear:\n");

            scanf("%d", &ele);
            printf("\ninserted element at rear  is %d\n", ele); // insert rear
            root = insertrear(root, ele);
            break;
        case 4: // delete rear
            root = deleterear(root);
            break;
        case 5:
            display(root);
            break;
        case 6:
            printf("enter the element to be searched :\n");
            scanf("%d", &element);
            pos = search(root, element);
            break;
        default:
            printf("invalid operation\n");
            break;
        }
    }
}
