#include<stdio.h>
#include<stdlib.h>
#define max 20
void array2d();
void readsparse(int [][3]);
void printsparse(int [][3]);
void transpose(int [][3],int [][3]);
void main()
{
    int a[max][3],b[max][3],m,n,i,j;
    printf("1. Dynamic memory allocation of 2d array :\n");
    array2d();
    printf("2. Demonstrate the working of sparse matrix transpose\n");
    printf("Enter row and column dimensions :");
    scanf("%d%d",&m,&n);
    a[0][0]=m;
    a[0][1]=n;
    readsparse(a);
    //printf("Transpose of the matrix ");
    transpose(a,b);
    printsparse(b);
}
void array2d()
{
    int **ptr,r,c,i,j;
    printf("Enter row and column dimensions : ");
    scanf("%d%d",&r,&c);
    ptr=(int**)malloc(r*sizeof(int*));
    for(i=0;i<r;i++)
    ptr[i]=(int*)malloc(c*sizeof(int));
    printf("Enter elements into the array :\n");
    for(i=0;i<r;i++)
    for(j=0;j<c;j++)
    scanf("%d",&ptr[i][j]);
    printf("Array elements are : \n");
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d\t",ptr[i][j]);
        }
        printf("\n");
    }

}
void readsparse(int a[max][3])
{
    int i,t;
    printf("\nEnter the no. of non zero elements : ");
    scanf("%d",&t);
    a[0][2]=t;
    for(i=1;i<=t;i++)
    {
        printf("\nEnter the next triplet (row,column,dimesion): ");
        scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
    }
}
void printsparse(int b[max][3])
{
    int n=b[0][2],i;
    printf("After transpose\n");
    printf("Row\tColumn\tValue\n");
    for(i=0;i<=n;i++)
    {
        printf("%d\t%d\t%d\n",b[i][0],b[i][1],b[i][2]);
    }
}
void transpose(int a[max][3],int b[max][3])
{
    int i,j,k,n;
    int rowterms[max],startingpos[max];
    b[0][0]=a[0][1];
    b[0][1]=a[0][0];
    b[0][2]=a[0][2];
    k=a[0][1];
    n=a[0][2];
    for(i=0;i<k;i++)
    {
        rowterms[i]=0;
    }
    for(i=1;i<n;i++)
    {
        rowterms[a[i][1]]++;
    }
    startingpos[0]=1;
    for(i=1;i<k;i++)
    {
        startingpos[i]=startingpos[i-1]+rowterms[i-1];
    }
    for(i=1;i<=n;i++)
    {
        j=startingpos[a[i][1]]++;
        b[j][0]=a[i][1];
        b[j][1]=a[i][0];
        b[j][2]=a[i][2];
    }
}