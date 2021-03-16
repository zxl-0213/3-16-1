#include<stdio.h>
#include<malloc.h>
typedef struct TreeNode
{
    char ch;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;
TreeNode* reBulid(char* a,int* pi)
{
    if(a[*pi]=='#')
    {
        return NULL;
    }
    else
    {
        TreeNode* root=(TreeNode*)malloc(sizeof(TreeNode));
        root->ch=a[*pi];
        (*pi)++;
        root->left=reBulid(a,pi);
        (*pi)++;
        root->right=reBulid(a,pi);
        return root;
    }
}

void inOrder(TreeNode* root)
{
    if(root==NULL)
    {
        return;
    }
    inOrder(root->left);
    printf("%c ",root->ch);
    inOrder(root->right);
}

int main()
{ 
    
    char a[100];
    scanf("%s",a);
    int i=0;
    TreeNode* root=reBulid(a,&i);
    inOrder(root);
    return 0;
}