#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define msize 10
struct stack
{
    int st[msize];
    int tos;
};
typedef struct stack s1;
int isFull(s1 s)
{
    if (s.tos == (msize - 1))
        return 1;
    else
        return 0;
}
void push(s1 *s, int item)
{
    if (isFull(*s) == 1)
        printf("stack is full or overflow");
    else
    {
        s->tos++;
        s->st[s->tos] = item;
    }
}
int isEmpty(s1 s)
{
    if (s.tos == -1)
        return 1;
    else
        return 0;
}
int pop(s1 *s)
{
    if (isEmpty(*s) == 1)
        return 9;

    int a = s->st[s->tos];
    s->tos--;
    return a;
}
int isPalindrome(char str[])
{
    s1 s;
    s.tos = -1;

    int length = strlen(str);

    // Push first half of the string onto the stack
    for (int i = 0; i < length / 2; i++)
    {
        push(&s, str[i]);
    }

    // Skip the middle character for odd-length strings
    int start = (length % 2 == 0) ? length / 2 : length / 2 + 1;

    // Compare the second half of the string with elements popped from the stack
    for (int i = start; i < length; i++)
    {
        if (pop(&s) != str[i])
        {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

void disp(s1 s)
{
    if (isEmpty(s) == 1)
        printf("stack is empty");
    else
    {
        printf("the element of stack is:\n ");
        for (int i = s.tos; i >= 0; i--)
            printf("%d\n", s.st[i]);
    }
}
void main()
{
    int choice, ele;
    s1 sta;
    sta.tos = -1;
    char str[20];
    while (1)
    {
        printf("enter the operation to be performed\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("enter the element to be pushed\n");
            scanf("%d", &ele);
            push(&sta, ele);
            break;
        case 2:
            ele = pop(&sta);
            if (ele == 9)
                printf("stack is empty");
            else
                printf("%d is popped element\n", ele);
            break;
        case 3:
            disp(sta);
            break;
        case 4:
            printf("\nEnter the string: ");
            scanf("%s", str);
            if (isPalindrome(str))
                printf("\nIs palindrome");
            else
                printf("\nIs not palindrome");
            break;

        default:
            exit(0);
        }
    }
}