#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
    public :
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode() {
        if(left)
            delete left;
        if(right)
            delete right;
    }
};

TreeNode<int>* LCAinaBST(TreeNode<int>* root, TreeNode<int>* P, TreeNode<int>* Q)
{
    TreeNode<int>* temp=root;
    if(temp==NULL){return NULL;}
    else if(temp->data<P->data&&temp->data<Q->data)
    {
        temp=temp->right;
        return LCAinaBST(temp,P,Q);
    }
    else if(temp->data>P->data&&temp->data>Q->data)
    {
        temp=temp->left;
        return LCAinaBST(temp,P,Q);
    }
    else if(temp->data>=P->data&&temp->data<=Q->data)
    {
        return temp;
    }
    else if(temp->data<=P->data&&temp->data>=Q->data)
    {
        return temp;
    }
}

int main()
{
    return 0;
}

