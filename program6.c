#include<stdio.h>
#include<stdlib.h>
struct BST
{
    int data;
    struct BST *right, *left;
};
typedef struct BST NODE;
NODE *Createtree(NODE *node,int data)
{
    if(node==NULL)
    {
        NODE *temp=(NODE*)malloc(sizeof(NODE));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    else if(data<(node->data))
    {
        node->left=Createtree(node->left,data);
    }
    else if(data>(node->data))
    {
        node->right=Createtree(node->right,data);
    }
    else{
        printf("\nDuplicate element is found\n");
    }
    return node;
}
NODE *Search(NODE *node,int data)
{
    if(node==NULL)
    {
        printf("\nElement not found\n ");
    }
    else if(data<(node->data))
    {
        node->left=Search(node->left,data);
    }
    else if(data>(node->data))
    {
        node->right=Search(node->right,data);
    }
    else{
        printf("\nElement is found\n");
    }
    return node;
}
void Preorder(NODE *node)
{
    if(node!=NULL)
    {
        printf("%d\t",node->data);
        Preorder(node->left);
        Preorder(node->right);
    }
}
void Postorder(NODE *node)
{
    if(node!=NULL)
    {
        
        Postorder(node->left);
        Postorder(node->right);
        
        printf("%d\t",node->data);
    }
}
void Inorder(NODE *node)
{
    if(node!=NULL)
    {
        
        Inorder(node->left);
        printf("%d\t",node->data);
        Inorder(node->right);
    }
}
void main()
{
    int data,ch,i,n,a[20];
    NODE *root=NULL;
    while(1)
    {
        printf("\n\n-----BINARY TREE-----\n");
        printf("\n1. Insertion\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter no. of elements : ");
            scanf("%d",&n);
            printf("\nEnter the values of BST :\n");
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                root=Createtree(root,a[i]);
            }
            break;
            case 2: printf("\nEnter the element to search : ");
            scanf("%d",&data);
            root=Search(root,data);
            break;
            case 3: printf("\nInorder traversal:\n");
            Inorder(root);
            break;
            case 4: printf("\nPreorder traversal:\n");
            Preorder(root);
            break;
            case 5: printf("\nPostorder traversal:\n");
            Postorder(root);
            break;
            case 6: exit(0);
            default: printf("\nInvalid choice\n");
            break;
        }
    }

}