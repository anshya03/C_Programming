#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
typedef struct node s;
s *getnode(int ele)
{
    s *ptr = (s *)malloc(sizeof(s));
    ptr->data = ele;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
}
s *insertfront(s *root, int ele)
{
    s *newnode = getnode(ele);
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    newnode->next = root;
    root->prev = newnode;
    root = newnode;
    return root;
}
s *insertrear(s *root, int ele)
{
    s *newnode = getnode(ele);
    if (root == NULL)
    {
        root = newnode;
        return root;
    }
    s *temp = root;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return root;
}
s *deletefront(s *root)
{
    if (root == NULL)
    {
        printf("no element to delete\n");
        return root;
    }
    if (root->next == NULL)
    {
        printf("deleted element is %d\n", root->data);
        free(root);
        return NULL;
    }
    s *temp = root;
    root = root->next;
    root->prev = NULL;
    printf("deleted element is %d\n", temp->data);
    free(temp);
    return root;
}
s *deleterear(s *root)
{
    if (root == NULL)
    {
        printf("no element to delete\n");
        return root;
    }
    if (root->next == NULL)
    {
        printf("deleted element is %d\n", root->data);
        free(root);
        return NULL;
    }
    s *temp, *prev;
    temp = root;
    prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("deleted element is %d\n", temp->data);
    free(temp);
    return root;
}
void display(s *root)
{
    if (root == NULL)
    {
        printf("List is empty\n");
        return;
    }
    s *temp = root;
    while (temp != NULL)
    {
        printf("Element: %d\n ", temp->data);
        temp = temp->next;
    }
}
int search(s *root, int element)
{
    int pos = 0;
    if (root == NULL)
    {
        printf("no elements\n");
        return -1;
    }
    s *temp = root;
    while (temp != NULL)
    {
        pos++;
        if (temp->data == element)
        {
            printf("the element is found at position %d\n", pos);
            return pos;
        }
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("element not found\n");
        return -1;
    }
}
int checkpallindrone(s *root)
{
    int count = 0;
    s *end;
    end = root;
    while (end->next != NULL)
    {
       // printf("%d  ", end->data);
        end = end->next;
        count++;
    }
    int i = 0;
    while (i <= count / 2)
    {
        if (root->data == end->data)
        {
            root = root->next;
            end = end->prev;
            i++;
        }
        else
            return 0;
    }
    return 1;
}
void main()
{
    s *root = NULL;
    int ele, choice, res, pal, pos;
    while (1)
    {
        printf("enter the operation to be performed\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to insert\n");
            scanf("%d", &ele);
            root = insertfront(root, ele);
            break;
        case 2:
            printf("enter the element to insert\n");
            scanf("%d", &ele);
            root = insertrear(root, ele);
            break;
        case 3:
            root = deletefront(root);
            break;
        case 4:
            root = deleterear(root);
            break;
        case 5:
            display(root);
            break;
        case 6:
            printf("enter the element to be searched :\n");
            scanf("%d", &ele);
            pos = search(root, ele);
            break;
        case 7:
            pal = checkpallindrone(root);
            if (pal == 0)
            {
                printf("\nDLL not pallindrone");
            }
            else
                printf("DLL is pallindrone");
            break;
        default:
            exit(0);
        }
    }
}