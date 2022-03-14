#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct queue
{
    int *arr;
    int size;
    int delete;
    int insert;
};

int empty_check(struct queue* e)
{
    if (e->delete==e->insert)
    {
        return 1;
    }
    else
    {
    return 0;
    }
}

int full_check(struct queue* e)
{
    if (e->insert==e->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void peek(struct queue* e,int index)
{
    // printf("We index from top to bottom in stack\n");
    // printf("Using the peek function\n");
    int a=e->insert-index+1; 
    printf("The value at given index is %d\n",e->arr[a]);
}

void transeversal(struct queue* e)
{
    for (int i = e->delete+1; i < e->insert+1; i++)
    {
        printf("element:-%d\n",e->arr[i]);
    }    
}

void enqueuer(struct queue* e,int data)
{
    if (full_check(e))
    {
        printf("The queue is full cannot enter the record!!!");
    }
    else
    {
    e->insert++;
    e->arr[e->insert]=data;
    }
};

int dequeuer(struct queue* e)
{
    if (e->insert==-1)
    {
        printf("The queue is full cannot enter the record!!!");
    return -1;
    }
    else
    {
    int val=e->arr[e->insert];
    e->insert--;
    return val;
    }
};

int dequeuef(struct queue* e)
{
    if (empty_check(e))
    {
        printf("The queue is empty cannot delete the record\n");
    return 0;
    }
    else
    {
    e->delete++;
    int a=e->arr[e->delete];
    return a;
    }
};

void enqueuef(struct queue* e,int data)
{
    if (e->delete==-1)
    {
        printf("The queue is full cannot enter the record!!!");
    }
    else
    {
    e->arr[e->delete]=data;
    e->delete--;
    }
};

int main()
{
    struct queue* e=(struct queue*)malloc(sizeof(struct queue));
    e->size=20;
    e->insert=e->delete=-1;
    e->arr=(int*)malloc(e->size*sizeof(int));


    enqueuer(e,5);
    enqueuer(e,15);
    enqueuer(e,25);
    enqueuer(e,35);
    enqueuer(e,45);
    enqueuer(e,55);
    enqueuer(e,65);
    enqueuer(e,75);
    peek(e,2);
    printf("Before\n");
    transeversal(e);
    printf("After\n");
    dequeuer(e);
    dequeuef(e);
    enqueuef(e,10);
    enqueuer(e,85);
    transeversal(e);
    return 0;
}