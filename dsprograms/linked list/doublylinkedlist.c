#include <stdio.h>
#include <stdlib.h>
struct dnode
{
    int data;
    struct dnode *next;
    struct dnode *prev;
};
typedef struct dnode d;
// get a new node
d *getnode(int info)
{
    d *ptr;
    ptr = (d *)malloc(sizeof(d));
    ptr->data = info;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}
// insert at front
d *insert_front(d *root, int data)
{
    printf("\nenter the element:");
    scanf("%d", &data);
    d *newnode = getnode(data);
    if (root == NULL)
    {
        return newnode;
    }
    newnode->next = root;
    root->prev = newnode;
    root = newnode;
    return root;
}
// insert at rear
d *insert_rear(d *root, int data)
{
    printf("\nenter the element:");
    scanf("%d", &data);
    d *newnode = getnode(data);
    if (root == NULL)
    {
        return newnode;
    }
    d *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return root;
}
// delete at front
d *deletefront(d *root)
{
    if (root == NULL)
    {
        printf("no elements are present");
        return root;
    }
    if (root->next == NULL)
    {
        free(root);
        return NULL;
    }
    d *temp = root;
    root = root->next;
    root->prev = NULL;
    free(temp);
    return root;
}
// delete at rear
d *deleterear(d *root)
{
    if (root == NULL)
    {
        printf("no elements are present");
        return root;
    }
    d *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    return root;
}
void display(d *root)
{
    if (root == NULL)
    {
        printf("\nno elements are present  ");
        return;
    }
    d *temp = root;
    printf("\n the elements are: ");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void main()
{
    d *root = NULL;
    int choice;
    while (1)
    {
        printf("enter the choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: // insert at front
            root = insert_front(root, 0);
            break;
        case 2: // insert at rear
            root = insert_rear(root, 0);
            break;
        case 3: // delete at front
            root = deletefront(root);
            break;
        case 4: // delete at rear
            root = deleterear(root);
            break;
        case 5: // display elements
            display(root);
            break;
        default:
            printf("invalid operation");
            break;
        }
    }
}