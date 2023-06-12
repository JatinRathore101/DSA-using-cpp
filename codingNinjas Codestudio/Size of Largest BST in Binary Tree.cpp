#include<bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
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

vector<int> BST(TreeNode<int>* root)
{
    if(root->left==NULL&&root->right==NULL){return {1,1,root->data,root->data};}

    vector<int> ans(4);
    vector<int> ans_left={1,0,root->data,root->data};
    vector<int> ans_right={1,0,root->data,root->data};

    if(root->left!=NULL){ans_left=BST(root->left);}
    if(root->right!=NULL){ans_right=BST(root->right);}

    if(ans_left[0]==1&&ans_right[0]==1&&root->data>=ans_left[3]&&root->data<=ans_right[2])
    {
        ans[0]=1;
        ans[1]=ans_left[1]+ans_right[1]+1;
        ans[2]=ans_left[2];
        ans[3]=ans_right[3];
    }
    else
    {
        ans[0]=0;
        ans[1]=max(ans_left[1],ans_right[1]);
        ans[2]=min(root->data,min(ans_left[2],ans_right[2]));
        ans[3]=max(root->data,max(ans_left[3],ans_right[3]));
    }

    return ans; // ans={isBST, maxSize, minimumNodeValue, maximumNodeValue} //
}

int largestBST(TreeNode<int>* root)
{
    if(root==NULL){return 0;}
    return BST(root)[1];
}

int main()
{
    return 0;
}
