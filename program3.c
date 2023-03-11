#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 20
int co=0,cp=0,top=-1;
char s[size];
void push(char elem)
{
    s[++top]=elem;
}
char pop()
{
    return(s[top--]);
}
int pr(char elem)
{
    switch(elem)
    {
        case '#': return 0;
                    break;
        case '(': return 1;
        break;
        case '+': return 2;
        break;
        case '-': return 2;
        break;
        case '*': return 3;
        break;
        case '/': return 3;
        break;
        case '^': return 4;
        break;
        default : return -1;
        break;
    }
}
void main()
{
    int k=0,prec,i=0;
    char infx[20],pofx[20],ch,elem;
    printf("Enter the infix expression : ");
    scanf("%s",infx);
    push('#');
    while((ch=infx[i++])!='\0')
    {
        if(ch=='(')
        {
            push(ch);
        }
        else if(isalnum(ch))
        {
            pofx[k++]=ch;
            co++;
        }
        else if(ch==')')
        {
            while(s[top]!='(')
            {
                pofx[k++]=pop();
            }
             elem=pop();
        }
        else
        {
            cp++;
            prec=pr(ch);
            if(prec==-1)
            {
                printf("invalid operator\n");
                exit(1);
            }
            else if(pr(s[top])>=prec)
            {
                pofx[k++]=pop();
            }
            push(ch);
        }
    }
    while(s[top]!='#')
    {
        if(s[top]=='(')
        {
            printf("Mismatched parenthesis\n");
            exit(0);
        }
        else if(cp!=(co-1))
        {
            printf("Invalid expression\n");
            exit(0);
        }
        else{
            pofx[k++]=pop();
        }
       

    }
     pofx[k]='\0';
        printf("Postfix expression : %s",pofx);
}