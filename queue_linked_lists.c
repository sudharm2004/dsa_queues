#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int data;
    struct node* next;
};

struct node* insert=NULL;
struct node* delete=NULL;

void transversal(struct  node *ptr)
{
    while (ptr!=NULL)
    {
        printf("Element:-%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int empty_check()
{
    if (delete==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int full_check()
{
    struct node* p=(struct node*)malloc(sizeof(struct node));
    if (p==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int val)
{
    struct node* ptr=(struct node*)malloc(sizeof(struct node));
    if (full_check())
    {
        printf("The queue is full cannot enter the record!!\n");
    }
    else
    {
        ptr->data=val;
        ptr->next=NULL;
        if (delete==NULL)
        {
            insert=delete=ptr;
        }
        else
        {
            insert->next=ptr;
            insert=ptr;
        }
    }
}

int dequeue()
{
    if (empty_check())
    {
        printf("The given queue is empty!!!");
    }
    else
    {
    struct node* ptr=delete;
    int val=ptr->data;
    delete=delete->next;
    free(ptr);
    return val;
    }
}

int main()
{
    enqueue(45);

    enqueue(75);

    enqueue(85);

    enqueue(95);

    transversal(delete);

    printf("value dequeued is %d\n",dequeue());

    transversal(delete);

    return 0;
}