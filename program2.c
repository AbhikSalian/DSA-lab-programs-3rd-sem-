#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void computeLPSArray(char* pat,int M,int* lps);
void KMPSearch(char* txt,char* pat);
void main()
{
    char txt[50],pat[50];
    printf("Enter the string : ");
    gets(txt);
    printf("Enter the pattern : ");
    gets(pat);
    KMPSearch(txt,pat);
}
void KMPSearch(char* txt,char* pat)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int lps[M];
    computeLPSArray(pat,M,lps);
    int i=0,j=0;
    while((N-i)>=(M-j))
    {
        if(pat[j]==txt[i])
        {
            i++;
            j++;
        }
        if(j==M)
        {
            printf("Pattern match found at index %d\n",i-j);
            j=lps[j-1];
        }
        else if(i<N && pat[j]!=txt[i])
        {
            if(j!=0)
            j=lps[j-1];
            else
            i=i+1;
        }
    }
    return -1;
}
void computeLPSArray(char* pat,int M,int* lps)
{
    int len=0;
    lps[0]=0;
    int i=1;
    while(i<M)
    {
        if(pat[i]==pat[len])
        {
            len++;
            lps[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
            {
                len=lps[len-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }
}