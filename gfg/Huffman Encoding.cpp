#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

class cmp
{
public:
    bool operator()(Node* temp1,Node* temp2)
    {
        return temp1->data>temp2->data;
    }
};

void preorder(Node* root,string S,vector<string> &ans)
{
    if(root==NULL){return;}
    if(root->left==NULL&&root->right==NULL){ans.push_back(S);}

    preorder(root->left,S+"0",ans);
    preorder(root->right,S+"1",ans);
}

vector<string> huffmanCodes(string S,vector<int> f,int N)
{
    priority_queue<Node*,vector<Node*>,cmp> pq;
    for(auto it:f)
    {
        Node* temp=new Node(it);
        pq.push(temp);
    }

    while(pq.size()>1)
    {
        Node* temp1=pq.top();pq.pop();
        Node* temp2=pq.top();pq.pop();

        Node* temp=new Node(temp1->data + temp2->data);
        temp->left=temp1;
        temp->right=temp2;
        pq.push(temp);
    }

    Node* root=pq.top();pq.pop();

    vector<string> ans;S="";
    preorder(root,S,ans);

    return ans;
}

/* // error //
void preorder(Node* root,string S,vector<string> &ans)
{
    if(root==NULL){return;}
    if(root->left==NULL&&root->right==NULL){ans.push_back(S);}

    preorder(root->left,S+"0",ans);
    preorder(root->right,S+"1",ans);
}

vector<string> huffmanCodes(string S,vector<int> f,int N)
{
    unordered_map<int,Node*> Map;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(auto it:f)
    {
        pq.push(it);
        Node* temp=new Node(it);
        Map[it]=temp;
    }

    while(pq.size()>1)
    {
        int a=pq.top();pq.pop();
        int b=pq.top();pq.pop();
        Node* temp=new Node(a+b);

        Map[a+b]=temp;
        Map[a+b]->left=Map[a];
        Map[a+b]->right=Map[b];
        pq.push(a+b);
    }

    Node* root=Map[pq.top()];

    vector<string> ans;S="";
    preorder(root,S,ans);
    return ans;
}
*/

int main()
{
    string S="abcdef";
    vector<int> f={5,9,12,13,16,45};
    int N=6;
    vector<string> ans=huffmanCodes(S,f,N);

    for(auto it:ans){cout<<it<<"  ";}
    return 0;
}

