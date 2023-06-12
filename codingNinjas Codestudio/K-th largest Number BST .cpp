#include<bits/stdc++.h>
using namespace std;

template<typename T>
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
};

void inorder(TreeNode<int>* root,vector<int> &v)
{
    if(root==NULL){return;}
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

int kthSmallest(TreeNode<int>* root, int k)
{
    if(root==NULL){return -1;}
    vector<int> v;
    inorder(root,v);
    if(v.size()>=k){return v[v.size()-k];}
    return -1;
}

int main()
{
    return 0;
}

