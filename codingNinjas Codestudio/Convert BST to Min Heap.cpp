#include<bits/stdc++.h>
using namespace std;

// to convert BST to min heap simply find inorder of BST and populate that inorder as preorder

class BinaryTreeNode
{
public :
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int data)
    {
        this -> left = NULL;
        this -> right = NULL;
        this -> data = data;
    }
};

BinaryTreeNode* convertBST(BinaryTreeNode* root)
{   // find inorder => convert it to preorder
    // L<N<R => N<L<R
    // see love babbar solution // gfg problem // convert BST to min heap
    // morris traversal used twice => 1. to find inorder // 2. to modify preorder

    vector<int> inorder;
    BinaryTreeNode* current=root;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            inorder.push_back(current->data);
            current=current->right;
        }
        else
        {
            BinaryTreeNode* temp=current->left;
            while(temp->right!=NULL&&temp->right!=current)
            {
                temp=temp->right;
            }
            if(temp->right==current){temp->right=NULL;inorder.push_back(current->data);current=current->right;}
            else{temp->right=current;current=current->left;}
        }
    }

    current=root;int i=0;

    while (current!=NULL)
    {
        if (current->left == NULL)
        {
            current->data=inorder[i++];
            current = current->right;
        }
        else
        {
            BinaryTreeNode* temp = current->left;
            while (temp->right && temp->right != current)
            {temp = temp->right;}

            if (temp->right == current)
            {
                temp->right = NULL;
                current = current->right;
            }

            else
            {
                current->data=inorder[i++];
                temp->right = current;
                current = current->left;
            }
        }
    }

    return root;
}

int main()
{
    return 0;
}

