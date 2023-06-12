#include<bits/stdc++.h>
using namespace std;

template<typename T>
class BinaryTreeNode
{
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
};

void inorder(BinaryTreeNode<int>* root,vector<int> &v)
{
    if(root==NULL){return;}
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

int kthSmallest(BinaryTreeNode<int>* root, int k)
{
    if(root==NULL){return -1;}
    vector<int> v;
    inorder(root,v);
    if(v.size()>=k){return v[k-1];}
    return -1;
}

int main()
{
    return 0;
}

