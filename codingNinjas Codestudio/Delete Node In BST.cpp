#include<bits/stdc++.h>
using namespace std;

template <typename T>
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

    ~BinaryTreeNode() {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};

BinaryTreeNode<int>* find_Parent(BinaryTreeNode<int>* root, int key)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        BinaryTreeNode<int>* temp=q.front();q.pop();

        if(temp->left!=NULL)
        {
            if(temp->left->data==key){return temp;}
            q.push(temp->left);
        }

        if(temp->right!=NULL)
        {
            if(temp->right->data==key){return temp;}
            q.push(temp->right);
        }
    }
    return NULL;
}

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key)
{
    if(root->data==key)
    {
        if(root->left==NULL&&root->right==NULL)
        {
            root=NULL;
        }
        else if(root->left!=NULL)
        {
            BinaryTreeNode<int>* temp=root->left;

            if(temp->right==NULL)
            {
                root->left=temp->left;
            }
            else
            {
                BinaryTreeNode<int>* parent=temp;
                temp=temp->right;
                while(temp->right!=NULL)
                {
                    parent=parent->right;
                    temp=temp->right;
                }
                parent->right=temp->left;
            }
            root->data=temp->data;
            temp->left=NULL;
        }
        else
        {
            BinaryTreeNode<int>* temp=root->right;

            if(temp->left==NULL)
            {
                root->right=temp->right;
            }
            else
            {
                BinaryTreeNode<int>* parent=temp;
                temp=temp->left;
                while(temp->left!=NULL)
                {
                    parent=parent->left;
                    temp=temp->left;
                }
                parent->left=temp->right;
            }
            root->data=temp->data;
            temp->right=NULL;
        }
    }
    else
    {
        BinaryTreeNode<int>* parent=find_Parent(root,key);
        if(parent!=NULL)
        {
            if(parent->left!=NULL&&parent->left->data==key)
            {
                parent->left=deleteNode(parent->left,key);
            }
            else
            {
                parent->right=deleteNode(parent->right,key);
            }
        }
    }
    return root;
}

int main()
{
    return 0;
}
