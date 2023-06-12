#include<bits/stdc++.h>
using namespace std;

template <typename T>
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

int noOfLeafNodes(BinaryTreeNode<int> *root) // recursion
{
    if(root->left==NULL&&root->right==NULL){return 1;}
    else if(root->left==NULL){return noOfLeafNodes(root->right);}
    else if(root->right==NULL){return noOfLeafNodes(root->left);}
    else {return noOfLeafNodes(root->left)+noOfLeafNodes(root->right);}
}

int noOfLeafNodes2(BinaryTreeNode<int> *root) // iteration => level order traversal
{
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    int count=0;

    while(!q.empty())
    {
        BinaryTreeNode<int>* temp=q.front();
        q.pop();

        if(temp->left==NULL&&temp->right==NULL){count++;}
        else
        {
            if(temp->left!=NULL){q.push(temp->left);}
            if(temp->right!=NULL){q.push(temp->right);}
        }
    }

    return count;
}

int main()
{
    return 0;
}

