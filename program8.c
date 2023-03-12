#include<stdio.h>
#include<stdlib.h>
#define MAX 10
struct employee
{
    int id;
    char name[20];
};
typedef struct employee EMP;
EMP emp[MAX];
int a[MAX];
static int count=0;
void Linear_prob(int key,int num)
{
    int flag=0,i=key;
    if(a[i]==-1)
    {
        flag=1;
        count++;
    }
    else{
        printf("\nCollision detected...!!!\n");
        i=(key+1)%MAX;
        do
        {
            if(a[i]==-1)
            {
                flag=1;
                count++;
                break;
            }
            else
            {
                i=(++i)%MAX;
            }
        } while(i!=key && flag==0 && count<MAX);
    }
        if(flag==0)
        {
            printf("\nHash table is full\n");

        }
        else{
            printf("\nEnter employee id and employee name : ");
            scanf("%d%s",&emp[i].id,emp[i].name);
            a[i]=i;
            printf("\nCollision avoided successfully using LINEAR PROBING\n");

        }
        
        
    
}
void Display()
{
    int i,ch;
    printf("\nHash table");
    printf("\nHT Key\tEmp ID \t EmpName");
    for(i=0;i<MAX;i++)
    printf("\n%d\t%d\t%s",i,emp[i].id,emp[i].name);
}
int main()
{
    int num,key,i;
    int ch=1;
    printf("\nCollision handling by linear probing: ");
    for(i=0;i<MAX;i++)
    a[i]=-1;
    do
    {
        printf("\nEnter the data (numeral):  ");
        scanf("%d",&num);
        Linear_prob( (num%MAX) , num);
        printf("\nDo you wish to continue? (1/0): ");
        scanf("%d",&ch);
    } while (ch);
    Display();
    return 0;
}