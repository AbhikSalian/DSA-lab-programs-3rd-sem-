#include<stdio.h>
#include<stdlib.h>
int MAX=4,count=0;
struct student
{
    char usn[10],name[20],branch[5],sem[1],phno[10];
    struct student *next;
};
typedef struct student NODE;
NODE* Getnode()
{
    NODE* temp=(NODE*)malloc(sizeof(NODE));
    printf("\nEnter USN, Name, Branch, Sem, Ph. no.\n");
    scanf("%s%s%s%s%s",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
    temp->next=NULL;
    count++;
    return temp;   
}
NODE* Display(NODE *start)
{
    NODE *ptr;
    if(start!=NULL)
    {
        ptr=start;
        printf("\n------STUDENT DATA------\n");
        printf("\nUSN\tNAME\t\tBRANCH\tSEM\tPH. NO.\n");
        while(ptr!=NULL)
        {
        printf("%s\t%s\t%s\t%s\t%s\n",ptr->usn,ptr->name,ptr->branch,ptr->sem,ptr->phno);
        ptr=ptr->next;
        }
    }
    if(start==NULL)
    {
        printf("\nNo data available\n");
    }
}
NODE* Insert(NODE *start, char ch)
{
    NODE *temp, *ptr;
    if(count==MAX)
    printf("\nOverflow\n");
    else
    {
        temp=Getnode();
        if(start==NULL)
        {
            start=temp;
        }
        else if(ch=='f')
        {
            temp->next=start;
            start=temp;
        }
        else if(ch=='r')
        {
            ptr=start;
            while(ptr!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=temp;
        }
        printf("\nInserted successfully\n");
    }
    return start;
}
NODE* Delete(NODE* start,char ch)
{
    NODE *temp, *ptr, *preptr;
    if(start==NULL)
    {
        printf("\nUnderflow\n");
    }
    else 
    {
        if(ch=='f')
        {
            ptr=start;
            start=start->next;
            free(ptr);
            count--;
        }
        else if(ch=='r')
        {
            if(start->next==NULL)
            start=NULL;
            else
            {
                ptr=start;
                while(ptr!=NULL)
                {
                    ptr=preptr;
                    ptr=ptr->next;
                }
                free(ptr);
                count--;
                preptr->next=NULL;
            }
        }
        printf("\nDeleted successfully\n");
    }
    return start;
}
void main()
{
    int choice,i;
    NODE *start=NULL;
    while(1)
    {
        printf("\n-----STUDENT DATABASE------\n");
        printf("\n1. Create\n2. Display\n3. Insert at the beginning\n4. Insert at the end\n5. Delete at the beginning\n6. Delete at the end\n7. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: Getnode();
            break;
            case 2: Display(start);
            break;
            case 3: start=Insert(start,'f');
            break;
            case 4: start=Insert(start,'r');
            break;
            case 5: start=Delete(start,'f');
            break;
            case 6: start=Delete(start,'r');
            break;
            case 7: exit(0);
            default: printf("\nInvalid choice\n");
        }
    }
}