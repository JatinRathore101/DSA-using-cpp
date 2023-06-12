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

/* // UNABLE TO DECT RUNTIME ERROR // MULTIPLE MORRIS TRAVERSALS USED IN THIS FUNCTION
TreeNode<int>* balancedBst(TreeNode<int>* root)
{
    if(root==NULL){return NULL;}

    vector<int> inorder;
    TreeNode<int>* current=root;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            inorder.push_back(current->data);
            current=current->right;
        }
        else
        {
            TreeNode<int>* temp=current->left;
            while(temp->right!=NULL&&temp->right!=current)
            {
                temp=temp->right;
            }
            if(temp->right==current){temp->right=NULL;inorder.push_back(current->data);current=current->right;}
            else{temp->right=current;current=current->left;}
        }
    }



    stack<TreeNode<int>*> s;
    current=root;
    while(current!=NULL)
    {
        if(current->left!=NULL)
        {
            TreeNode<int>* temp=current->left;

            while(temp->right!=NULL)
            {
                temp=temp->right;
            }

            temp->right=current->right;
            current->right=current->left;
            temp=current;
            current=current->left;
            temp->left=NULL;

        }
        else
        {
            current=current->right;
        }
    }

    while(root!=NULL)
    {
        s.push(root);
        current=root;
        root=root->right;
        current->right=NULL;
        current->left=NULL;
    }

    queue<TreeNode<int>*> q;
    q.push(s.top());s.pop();
    root=q.front();

    while(!q.empty())
    {
        current=q.front();
        q.pop();
        current->left=NULL;
        current->right=NULL;

        if(!s.empty())
        {
            current->left=s.top();
            q.push(current->left);
            s.pop();
        }

        if(!s.empty())
        {
            current->right=s.top();
            q.push(current->right);
            s.pop();
        }
    }


    current=root;int i=0;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            current->data=inorder[i++];
            current=current->right;
        }
        else
        {
            TreeNode<int>* temp=current->left;
            while(temp->right!=NULL&&temp->right!=current)
            {
                temp=temp->right;
            }
            if(temp->right==current){temp->right=NULL;current->data=inorder[i++];current=current->right;}
            else{temp->right=current;current=current->left;}
        }
    }

    return root;
}
*/

TreeNode<int>* build_Balanced_BST(int i,int j,vector<int> &inorder)
{
    if(i>j){return NULL;}

    int mid=(i+j)/2;
    TreeNode<int>* temp=new TreeNode<int>(inorder[mid]);

    temp->left=build_Balanced_BST(i,mid-1,inorder);
    temp->right=build_Balanced_BST(mid+1,j,inorder);

    return temp;
}

TreeNode<int>* balancedBst(TreeNode<int>* root)
{
    if(root==NULL){return NULL;}

    vector<int> inorder;
    TreeNode<int>* current=root;
    while(current!=NULL)
    {
        if(current->left==NULL)
        {
            inorder.push_back(current->data);
            current=current->right;
        }
        else
        {
            TreeNode<int>* temp=current->left;
            while(temp->right!=NULL&&temp->right!=current)
            {
                temp=temp->right;
            }
            if(temp->right==current){temp->right=NULL;inorder.push_back(current->data);current=current->right;}
            else{temp->right=current;current=current->left;}
        }
    }

    return build_Balanced_BST(0,inorder.size()-1,inorder);
}

int main()
{
    TreeNode<int>* root=new TreeNode<int>(60);
    root->left=new TreeNode<int>(50);
    root->right=new TreeNode<int>(70);
    root->left->left=new TreeNode<int>(40);
    root->left->right=new TreeNode<int>(55);
    root->left->right->left=new TreeNode<int>(53);
    root->left->right->right=new TreeNode<int>(57);
    TreeNode<int>* ruut=balancedBst(root);
    return 0;
}



