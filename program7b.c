#include<stdio.h>
int getMax(int array[],int size)
{
    int max=array[0];
    for(int i=1;i<size;i++)
    {
        if(array[i]>max)
        max=array[i];
    }
    return max;
}

void countingSort(int array[],int size,int place)
{
    int output[size+1];
    int max=(array[0]/place)%10;
    int i;
    for(i=1;i<size;i++)
    {
        if(((array[i]/place)%10)>max)
        max=array[i];
    }
    int count[max+1];
    for(i=0;i<max;i++)
    {
        count[i]=0;
    }
    for(i=0;i<size;i++)
    {
        count[(array[i]/place)%10]++;
    }
    for(i=1;i<10;i++)
    {
        count[i]+=count[i-1];
    }
    for(i=size-1;i>=0;i--)
    {
        output[count[(array[i]/place)%10]-1]=array[i];
        count[(array[i]/place)%10]--;
    }
    for(i=0;i<size;i++)
    {
        array[i]=output[i];
    }
}
void radixSort(int array[],int size)
{
    int place;
    int max=getMax(array,size);
    for(place=1;max/place>0;place*=10)
    countingSort(array,size,place);
}
void printArray(int array[],int size)
{
    printf("\nSorted array is :\n");
    for(int i=0;i<size;i++)
    {
        printf("%d\t",array[i]);
    }
    printf("\n");
}
void main()
{
    int array[]={6782,2,132,532,121,45,1,500,1230,34};
    int n=10;
    radixSort(array,n);
    printArray(array,n);
}