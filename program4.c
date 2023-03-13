#include<stdio.h>
#include<stdlib.h>
#define max 3
int queue[max];
int front=-1,rear=-1;
int count=0;
void insert(int elem)
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=elem;
        count++;
    }
    else if((rear+1)%max==front)
    {
        printf("\nQueue overflow");
    }
    else
    {
        rear=(rear+1)%max;
        queue[rear]=elem;
        count++;
    }
}
int delete()
{
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty");
    }
    else if(front==rear)
    {
        printf("\nThe deleted element is %d\n",queue[front]);
        front=-1;
        rear=-1;
        count--;
    }
    else
    {
        printf("\nThe deleted element is %d\n",queue[front]);
        front=(front+1)%max;
        count--;
    }
}
void display()
{
    int i,j;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElements of the queue are :");
        i=(front)%max;
        for(j=1;j<=count;j++)
        {
            printf("%d\t",queue[i]);
            i=(i+1)%max;
        }
    }
}
void main()
{
    int choice,x;
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("\nEnter the element which is to be inserted : ");
            scanf("%d",&x);
            insert(x);
            break;
            case 2: delete();
            break;
            case 3: display();
            break;
            case 4: exit(0);
        }
    }
}
