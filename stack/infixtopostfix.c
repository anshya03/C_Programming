#include <stdio.h>
#define max 20
#include <ctype.h>
#include <string.h>
struct stack
{
    char st[max];
    int tos;
};
typedef struct stack s;
int in_p(char symb)
{
    switch (symb)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '$':
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    }
}
int st_p(char symb)
{
    switch (symb)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '$':
    case '^':
        return 5;
    case '(':
        return 0;
    case '#':
        return -1;
    }
}

int isfull(s s1)
{
    if (s1.tos == max - 1)
        return 1;
    else
        return 0;
}
void push(s *p, char item)
{
    if (isfull(*p) == 1)
        printf("The stack is full");
    else
    {
        p->tos++;
        p->st[p->tos] = item;
    }
}
int isempty(s s1)
{
    if (s1.tos == -1)
        return 1;
    else
        return 0;
}
char pop(s *p)
{
    if (isempty(*p) == 1)
        printf("stack is empty");
    else
    {
        return (p->st[p->tos--]);
    }
}
void in_post(char infix[], char postfix[])
{
    s s1;
    s1.tos = -1;
    push(&s1, '#');
    int j = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        char symb = infix[i];
        if (isalpha(symb))
        {
            postfix[j] = symb;
            j++;
        }
        else
        {
            while (in_p(symb) < st_p(s1.st[s1.tos]))
            {
                char ele = pop(&s1);
                postfix[j] = ele;
                j++;
            }
            if (in_p(symb) != st_p(s1.st[s1.tos]))
            {
                push(&s1, symb);
            }
            else
            {
                char ele = pop(&s1);
            }
        }
    }
    while (s1.st[s1.tos] != '#')
    {
        postfix[j] = pop(&s1);
        j++;
    }
    postfix[j] = '\0';
}
void main()
{
    char infix[20], postfix[20];
    scanf("%s", infix);
    in_post(infix, postfix);
    printf("\nThe postfix expression is: %s", postfix);
}