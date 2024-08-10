// pointyers types of pointers
// double, null , void, pointer to pointer, pointer to function, pointer to array, pointer to structure, pointer to union, pointer to enum, pointer to typedef, pointer to const, pointer to volatile, pointer to restrict, pointer to function returning pointer, pointer to function returning array, pointer to function returning structure, pointer to function returning union, pointer to function returning enum, pointer to function returning typedef, pointer to function returning const, pointer to function returning volatile, pointer to function returning restrict, pointer to function returning function, pointer to function returning void, pointer to function returning null, pointer to function returning double, pointer to function returning pointer to pointer, pointer to function returning pointer to array, pointer to function returning pointer to structure, pointer to function returning pointer to union, pointer to function returning pointer to enum, pointer to function returning pointer to typedef, pointer to function returning pointer to const, pointer to function returning pointer to volatile, pointer to function returning pointer to restrict, pointer to function returning pointer to function, pointer to function returning pointer to void, pointer to function returning pointer to null, pointer to function returning pointer to double, pointer to function returning pointer to pointer to pointer, pointer to function returning pointer to pointer to array, pointer to function returning pointer to pointer to structure, pointer to function returning pointer to pointer to union, pointer to function returning pointer to pointer to enum, pointer to function returning pointer to pointer to typedef, pointer to function returning pointer to pointer to const, pointer to function returning pointer to pointer to volatile, pointer to function returning pointer to pointer to restrict, pointer to function returning pointer to pointer to function, pointer to function returning pointer to pointer to void, pointer to function returning pointer to pointer to null, pointer to function returning pointer to pointer to double, pointer to function returning pointer to pointer to pointer to pointer, pointer to function returning pointer to pointer to pointer to array, pointer to function returning pointer to pointer to pointer to structure, pointer to function returning pointer to pointer to pointer to union, pointer to function returning pointer to pointer to pointer to enum, pointer to function returning pointer to pointer to pointer to typedef, pointer to function returning pointer to pointer to pointer to const, pointer to function returning pointer to pointer to pointer to volatile, pointer to function returning pointer to pointer to pointer to restrict, pointer to function returning pointer to pointer to pointer to function, pointer to function returning pointer to pointer to pointer to void, pointer to function returning pointer to pointer to pointer to null, pointer to

#include <stdio.h>
#include <string.h>
#pragma pack(1) // try with commenting and uncomminting pragma

void display(int *a, int n);

struct a
{
    int b;
    int c;
    char d;
};

struct b
{
    int b;
    char d;
};

struct c
{
    int b;
    float c;
    char d;
};

struct student
{
    int roll;
    char name[30];
    int marks;
} student1, student2;

int main()
{
    printf("hello world!");
    int ab = 10;
    int b[5] = {1, 2, 3, 4, 5};
    int *p, **z;
    p = &ab;
    z = &p;
    printf("the address of a is : %p\n", p);
    printf("the value of a is : %d\n", *p);
    printf("the address of p is : %p\n", z);
    printf("the value of p is : %d\n", **z);
    display(b, 4);
    printf("the size of a is : %d\n", sizeof(struct a));
    printf("the size of b is : %d\n", sizeof(struct b));
    printf("the size of c is : %d\n", sizeof(struct c));
    student1.roll = 1;
    student1.marks = 100;
    student2.roll = 2;
    student2.marks = 50;
    strcpy(student1.name, "sachin");
    strcpy(student2.name, "student2");
    printf("the roll of student1 is : %d\n", student1.roll);
    printf("the name of student1 is : %s\n", student1.name);
    printf("the marks of student1 is : %d\n", student1.marks);
    printf("the roll of student2 is : %d\n", student2.roll);
    printf("the name of student2 is : %s\n", student2.name);
    printf("the marks of student2 is : %d\n", student2.marks);
    return 0;
}

void display(int *a, int n)
{
    printf("the array is : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}