// postfix evaluation #include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define max 20
struct stack
{
    int tos;
    double st[max];
};
typedef struct stack s;
int isFull(s s1)
{
    if (s1.tos == max - 1)
        return 1;
    return 0;
}
int isEmpty(s s1)
{
    if (s1.tos == -1)
        return 1;
    return 0;
}
void push(s *p, double item)
{
    if (isFull(*p) == 1)
        printf("stack overflow");
    else
    {
        p->tos++;
        p->st[p->tos] = item;
    }
}
double pop(s *p)
{
    if (isEmpty(*p) == 1)
        printf("stack is empty");
    else
        return p->st[p->tos--];
}
double operation(double op1, char symb, double op2)
{
    switch (symb)
    {
    case '+':
        return (op1 + op2);
        break;
    case '-':
        return (op1 - op2);
        break;
    case '*':
        return (op1 * op2);
        break;
    case '/':
        if (op2 == 0)
            printf("error");
        return (op1 / op2);
        break;
    case '$':
        return (pow(op1, op2));
        break;
    default:
        exit(0);
    }
}
double post_eval(char postfix[])
{
    s s1;
    s1.tos = -1;
    char op1, op2;
    push(&s1, '#');
    for (int i = 0; i < strlen(postfix); i++)
    {
        char symb = postfix[i];
        if (isdigit(symb))
        {
            push(&s1, symb - '0');
        }
        else
        {
            op2 = pop(&s1);
            op1 = pop(&s1);
            return operation(op1, symb, op2);
        }
    }
}
void main()
{
    char postfix[10];
    printf("Enter the postfix rxpression:");
    scanf("%s", postfix);
    double res = post_eval(postfix);
    printf("The result of evaluation is %lf", res);
}