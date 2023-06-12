#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

void inorder(BinaryTreeNode<int> *root,int &x,bool &ans)
{
    if(root==NULL){return;}
    inorder(root->left,x,ans);
    if(root->data<x){ans=false;}
    x=root->data;
    inorder(root->right,x,ans);
}

bool validateBST(BinaryTreeNode<int> *root)
{
    if(root==NULL){return true;}

    bool ans=true;
    int x=INT_MIN;
    inorder(root,x,ans);
    return ans;
}

int main()
{
    BinaryTreeNode<int> *root=NULL;
    cout<<::boolalpha<<validateBST(root);
    return 0;
}


