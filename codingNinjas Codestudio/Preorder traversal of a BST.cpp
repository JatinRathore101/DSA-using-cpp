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

/* // partially accepted // high time complexity
BinaryTreeNode<int>* buildTree(int in[],int pre[],int n)
{
    if(n<=0){return NULL;}
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(pre[0]);
    int j=-1;
    for(int i=0;i<n;i++){if(in[i]==pre[0]){j=i;break;}}

    if(j>0){root->left=buildTree(in,pre+1,j);}
    if(j!=-1&&j<n-1){root->right=buildTree(in+j+1,pre+j+1,n-j-1);}
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder)
{
    int n=preorder.size();
    if(n<1){return NULL;}
    vector<int> inorder=preorder;
    sort(inorder.begin(),inorder.end());

    int in[5001],pre[5001];
    for(int i=0;i<n;i++)
    {
        in[i]=inorder[i];
        pre[i]=preorder[i];
    }
    return buildTree(in,pre,n);
}
*/

/*
BinaryTreeNode<int>* buildTree(int left,int right,vector<int> &preorder)
{
    if(left>right){return NULL;}
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(preorder[left]);
    if(left==right){return root;}

    int mid=left;while(preorder[mid+1]<preorder[left]&&mid<right){mid++;}

    root->left=buildTree(left+1,mid,preorder);
    root->right=buildTree(mid+1,right,preorder);
    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder)
{
    if(preorder.size()<1){return NULL;}
    return buildTree(0,preorder.size()-1,preorder);
}
*/

BinaryTreeNode<int>* buildTree(int left_val,int right_val,int &root_index,vector<int> &preorder)
{
    if(root_index>=preorder.size()){return NULL;}

    int root_val=preorder[root_index];
    if(root_val<left_val||root_val>right_val){return NULL;}

    //N
    BinaryTreeNode<int>* root=new BinaryTreeNode<int>(root_val);
    root_index++;

    //L
    root->left=buildTree(left_val,root_val,root_index,preorder);

    //R
    root->right=buildTree(root_val,right_val,root_index,preorder);

    return root;
}

BinaryTreeNode<int>* preorderToBST(vector<int> &preorder)//NLR
{
    if(preorder.size()<1){return NULL;}
    int root_index=0;
    return buildTree(INT_MIN,INT_MAX,root_index,preorder);
}


int main()
{
    vector<int> preorder={1,4,2,5,3,7,6};
    BinaryTreeNode<int>* root = preorderToBST(preorder);
    return 0;
}

