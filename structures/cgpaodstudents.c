// Online C compiler to run C program online
#include <stdio.h>
struct student
{
    char name[20];
    int usn, sem;
    float cgpa;
};
typedef struct student s;
void read(s *p)
{
    printf("STUDENT NAME:");
    scanf("%s", p->name);
    printf("USN:");
    scanf("%d", &p->usn);
    printf("SEM:");
    scanf("%d", &p->sem);
    printf("CGPA:");
    scanf("%f", &p->cgpa);
}
void write(s s1)
{
    printf("STUDENT NAME:%s\n", s1.name);

    printf("USN:%d\n", s1.usn);

    printf("SEM:%d\n", s1.sem);

    printf("CGPA:%f\n", s1.cgpa);
}
void main()
{
    int n;
    int i;
    printf("enter the number of students enrolled:");
    scanf("%d", &n);
    s s1[n];
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d\n", i + 1);
        read(&s1[i]);
    }
    for (i = 0; i < n; i++)
    {
        write(s1[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (s1[i].cgpa >= 8.5)
        {
            printf("the students above 8.5 cgpa are:\n");
            write(s1[i]);
        }
    }
}