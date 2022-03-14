#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct circularqueue
{
    int *arr;
    int size;
    int delete;
    int insert;
};

int empty_check(struct circularqueue* e)
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

int full_check(struct circularqueue* e)
{
    if ((e->insert+1)%e->size==e->delete)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void peek(struct circularqueue* e,int index)
{
    // printf("We index from top to bottom in stack\n");
    // printf("Using the peek function\n");
    int a=e->insert-index+1; 
    printf("The value at given index is %d\n",e->arr[a]);
}

void transeversal(struct circularqueue* e)
{
    int i=e->delete;
    int j=e->insert;

    while (e->insert!=e->delete)
    {
        e->delete=(e->delete+1)%e->size;
        printf("element:-%d\n",e->arr[e->delete]);
    }
    e->delete=i;
    e->insert=j;  
}

void insert(struct circularqueue* e,int data)
{
    if (full_check(e))
    {
        printf("The queue is full cannot enter the record!!!\n");
    }
    else
    {
    e->insert=(e->insert+1)%(e->size);
    e->arr[e->insert]=data;
    }
};

int delete(struct circularqueue* e)
{
    if (empty_check(e))
    {
        printf("The queue is empty cannot delete the record\n");
    return 0;
    }
    else
    {
    e->delete=(e->delete+1)%(e->size);
    int a=e->arr[e->delete];
    return a;
    }
};

int main()
{
    struct circularqueue* e=(struct circularqueue*)malloc(sizeof(struct circularqueue));
    e->size=4;
    e->insert=e->delete=0;
    e->arr=(int*)malloc(e->size*sizeof(int));

//we can n-1 elements in circular queue cause 1 element is reserved for 0 and circular queue are 100 times more functional and good rather than normal queue
 
    insert(e,5);
    insert(e,15);
    insert(e,25);
    printf("before:-\n");
    transeversal(e);
    delete(e);
    delete(e);
    delete(e);
    insert(e,35);
    printf("after:-\n");
    transeversal(e);
    insert(e,45);
    insert(e,55);
    insert(e,65);
    transeversal(e);

    printf("\n\n\n");
    return 0;
}