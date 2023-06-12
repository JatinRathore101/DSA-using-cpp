#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode()
        {
            if(left){delete left;}
            if(right){delete right;}
        }
};

void inorder(TreeNode<int> *root)
{
    if(root==NULL){return;}
    inorder(root->left);
    cout<<root->data<<"  ";
    inorder(root->right);
}

TreeNode<int> *BST_to_DLL(TreeNode<int> *root)
{
    if(root==NULL){return NULL;}
    TreeNode<int>* Left=BST_to_DLL(root->left);
    TreeNode<int>* Right=BST_to_DLL(root->right);
    TreeNode<int>* temp=NULL;

    if(Left!=NULL)
    {
        temp=Left;
        while(temp->right!=NULL)
        {temp=temp->right;}

        temp->right=root;
        root->left=temp;
        temp=root;
        root=Left;
    }
    else
    {
        temp=root;
    }

    temp->right=Right;

    if(Right!=NULL)
    {
        Right->left=temp;
    }

    return root;
}

TreeNode<int> *DLL_to_BST(TreeNode<int> *DLL)
{
    if(DLL==NULL){return NULL;}
    else if(DLL->right==NULL){return DLL;}

    TreeNode<int>* slow=DLL;
    TreeNode<int>* fast=DLL;

    while(fast!=NULL&&fast->right!=NULL)
    {
        slow=slow->right;
        fast=fast->right->right;
    }


    fast=slow->left;fast->right=NULL;slow->left=NULL;slow->left=DLL_to_BST(DLL);

    if(slow->right!=NULL){fast=slow->right;fast->left=NULL;slow->right=NULL;slow->right=DLL_to_BST(fast);}

    return slow;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    TreeNode<int>* DLL1=BST_to_DLL(root1);
    TreeNode<int>* DLL2=BST_to_DLL(root2);

    TreeNode<int>* DLL=NULL;
    TreeNode<int>* Tail=NULL;

    while(DLL1!=NULL&&DLL2!=NULL)
    {
        TreeNode<int>* temp=NULL;
        if(DLL1->data<DLL2->data)
        {
            temp=DLL1;DLL1=DLL1->right;
            if(DLL1!=NULL){DLL1->left=NULL;}
            temp->right=NULL;
        }
        else
        {
            temp=DLL2;DLL2=DLL2->right;
            if(DLL2!=NULL){DLL2->left=NULL;}
            temp->right=NULL;
        }

        if(DLL==NULL){DLL=temp;Tail=temp;}
        else{Tail->right=temp;temp->left=Tail;Tail=Tail->right;}
    }

    if(DLL1!=NULL)
    {
        if(DLL==NULL){DLL=DLL1;Tail=DLL1;}
        else{Tail->right=DLL1;DLL1->left=Tail;}
    }

    if(DLL2!=NULL)
    {
        if(DLL==NULL){DLL=DLL2;Tail=DLL2;}
        else{Tail->right=DLL2;DLL2->left=Tail;}
    }

    return DLL_to_BST(DLL);
}

int main()
{
    TreeNode<int>* root1=new TreeNode<int>(5);
    root1->left=new TreeNode<int>(1);
    root1->left->left=new TreeNode<int>(0);
    root1->left->right=new TreeNode<int>(3);
    root1->right=new TreeNode<int>(6);


    TreeNode<int>* root2=new TreeNode<int>(7);
    root2->right=new TreeNode<int>(8);
    root2->right->right=new TreeNode<int>(9);
    root2->left=new TreeNode<int>(2);
    root2->left->right=new TreeNode<int>(4);

    TreeNode<int>* root3=mergeBST(root1,root2);
    inorder(root3);
    return 0;
}
