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
        printf("%d\n",e->arr[i]);
    }    
}

void insert(struct queue* e,int data)
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

int delete(struct queue* e)
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

int main()
{
    struct queue* e=(struct queue*)malloc(sizeof(struct queue));
    e->size=8;
    e->insert=e->delete=-1;
    e->arr=(int*)malloc(e->size*sizeof(int));

    if (empty_check(e)==1)
    {
        printf("The queue is empty\n");
    }
    delete(e);
    insert(e,5);
    insert(e,15);
    insert(e,25);
    insert(e,35);
    insert(e,45);
    insert(e,55);
    insert(e,65);
    insert(e,75);
    peek(e,2);
    printf("Before\n");
    transeversal(e);
    printf("After\n");
    printf("The value dequeued is %d\n",delete(e));
    printf("The value dequeued is %d\n",delete(e));
    printf("The value dequeued is %d\n",delete(e));
    printf("The value dequeued is %d\n",delete(e));
    printf("The value dequeued is %d\n",delete(e));
    printf("The value dequeued is %d\n",delete(e));
    printf("The value dequeued is %d\n",delete(e));
    printf("The value dequeued is %d\n",delete(e));

    //now as per we gave condition that if insert=delte queue is empty and insert=size-1 ......both condition are satisfied hence both condition runs
    
    if (empty_check(e))
    {
        printf("The queue is empty\n");
    }
    if (full_check(e))
    {
        printf("The queue is full\n");
    }
    transeversal(e);
    return 0;
}