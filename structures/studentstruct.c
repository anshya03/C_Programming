// Online C compiler to run C program onlin#include <stdio.h>
// write read and write function for the student program pass by refrance
struct student
{
    int age;
    int roll_no;
    char name[50];
    float totalmarks;
};
typedef struct student s1;
void read(s1 *p);
void write(s1 p);

#include <stdio.h>
int main()
{
    s1 stud1;
    s1 stud2;
    read(&stud1);
    read(&stud2);
    write(stud1);
    write(stud2);
}
void read(s1 *p)
{
    printf("enter the age\n");
    scanf("%d", &p->age);
    printf("enter roll number\n");
    scanf("%d", &p->roll_no);
    printf("enter name\n");
    scanf("%s", p->name);
    printf("enter total marks\n");
    scanf(" %f", &p->totalmarks);
}
void write(s1 p)
{
    printf("the age is %d\n", p.age);
    printf("the roll no is is %d\n", p.roll_no);
    printf("the name is %s\n", p.name);
    printf("the totalmarks are %f\n", p.totalmarks);
}
