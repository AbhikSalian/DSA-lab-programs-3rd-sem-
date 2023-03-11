#include<stdio.h>
#include<stdlib.h>
#define max 3
int queue[max];
int front=-1,rear=-1;
void insert(int elem)
{
    if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=elem;
    }
    else if((rear+1)%max==front)
    {
        printf("\nQueue overflow");
    }
    else
    {
        rear=(rear+1)%max;
        queue[rear]=elem;
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
    }
    else
    {
        printf("\nThe deleted element is %d\n",queue[front]);
        front=(front+1)%max;
    }
}
void display()
{
    int i;
    if(front==-1 && rear==-1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nElements of the queue are :");
        for(i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
    }
}
void main()
{
    int choice,x;
    while(1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit");
        printf("Enter your choice : ");
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