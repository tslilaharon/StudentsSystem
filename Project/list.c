#include <stdlib.h>
#include <string.h>
#include "list.h"

static Student* head = NULL;
Student* get_head()
{
    return head;
}
Student* get_next(Student* current)
{
    if (current == NULL)
    {
        return NULL;
    }
    return current->next;
}
void Add(int id, char* name, char* lastname, char* phone, char* address, float avarage, int age, int day, int month, int year)
{
    Student* student = (Student*)malloc(sizeof(Student));
    student->id = id;
    strcpy(student->name, name);
    strcpy(student->lastname, lastname);
    student->age = age;
    strcpy(student->address, address);
    strcpy(student->phone, phone);
    student->avarage = avarage;
    student->day = day;
    student->month = month;
    student->year = year;
    student->next = NULL;

    if (head == NULL)
    {
        head = student;
    }
    else
    {
        student->next = head;
        head = student;
    }
}
void UpAvargae(Student* student, float a)
{
    if (student == NULL)
    {
        return;
    }
    student->avarage = a;
}
Student* Search(int id)
{
    Student* student = head;
    while (student != NULL)
    {
        if (student->id == id)
        {
            return student;
        }
        student = student->next;
    }
    return NULL;
}
int Delete(int id)
{
    Student* t1 = head;
    Student* t2 = head;


    while (t1 != NULL)
    {
        if (t1->id == id)
        {
            if (t1 == t2)
            {
                head = head->next;
                free(t1);
            }
            else
            {
                t2->next = t1->next;
                free(t1);
            }
            return 1;
        }
        t2 = t1;
        t1 = t1->next;
    }
    return 0;
}
void Deletealist()
{
    Student* current = head;
    Student* next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}
