#include<bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode
{
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode()
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
};

void inorder(BinaryTreeNode<int>* root, int key,pair<int,int> &p)
{
    if(root==NULL){return;}
    inorder(root->left,key,p);
    if(root->data<key){p.first=root->data;}
    if(root->data>key&&p.second==-1){p.second=root->data;}
    inorder(root->right,key,p);
}

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    pair<int,int> p={-1,-1};
    inorder(root,key,p);
    return p;
}

int main()
{
    return 0;
}
