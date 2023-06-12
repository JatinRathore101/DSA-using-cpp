#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
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

/* // TLE
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(root==NULL){return false;}

    int x=-1;
    if(k%2==0){x=k/2;}

    unordered_map<int,int> M;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        BinaryTreeNode<int>* temp=q.front();
        q.pop();
        int a=temp->data;int b=k-a;
        if(a!=x){M[a]++;if(M[a]==2){return true;}}
        if(b!=x){M[b]++;if(M[b]==2){return true;}}

        if(temp->left!=NULL){q.push(temp->left);}
        if(temp->right!=NULL){q.push(temp->right);}
    }
}
*/

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    if(root==NULL){return false;}

    BinaryTreeNode<int>* current=root;
    vector<int> inorder;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            inorder.push_back(current->data);
            current=current->right;
        }
        else
        {
            BinaryTreeNode<int>* temp=current->left;
            while(temp->right!=NULL&&temp->right!=current)
            {
                temp=temp->right;
            }
            if(temp->right==current)
            {
                temp->right=NULL;
                inorder.push_back(current->data);
                current=current->right;
            }
            else
            {
                temp->right=current;
                current=current->left;
            }
        }
    }

    int i=0,j=inorder.size()-1;
    while(i<j)
    {
        if(inorder[i]+inorder[j]==k){return true;}
        else if(inorder[i]+inorder[j]<k){i++;}
        else{j--;}
    }
    return false;
}

int main()
{
    return 0;
}
