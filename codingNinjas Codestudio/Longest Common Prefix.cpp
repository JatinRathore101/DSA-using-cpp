#include<bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &arr, int n) // brute force
{
    int minLength=INT_MAX;
    for(auto it:arr)
    {
        int strLen=it.size();
        minLength=min(minLength,strLen);
    }

    int i=0,f=0;
    for(auto it:arr[0])
    {
        for(auto gt:arr)
        {
            if(gt[i]!=it){f=1;break;}
        }
        if(f==1){break;}i++;
        if(i==minLength){break;}
    }
    return arr[0].substr(0,i);
}

/* // trie solution // gives TLE //
class TrieNode
{
public:

    char data;
    TrieNode* children[26];
    int childrenCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data=ch;

        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }

        childrenCount=0;

        isTerminal=false;
    }
};

class Trie
{
public:
    TrieNode* root;

    Trie()
    {
        root=new TrieNode('\0');
    }

    void insertUtil(TrieNode* root,string word)
    {
        if(word.size()==0){root->isTerminal=true;return;}
        if(root->children[word[0]-'a']==NULL)
        {
            root->children[word[0]-'a']=new TrieNode(word[0]);
            root->childrenCount++;
        }
        insertUtil(root->children[word[0]-'a'],word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root,word);
    }

    string LongestCommonPrefix(string word)
    {
        TrieNode* temp=root;
        int i=0;
        while(temp->childrenCount==1&&temp->isTerminal==false)
        {
            temp=temp->children[word[i]-'a'];
            i++;
        }

        return word.substr(0,i);
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie t;
    for(auto it:arr){t.insert(it);}
    return t.LongestCommonPrefix(arr[0]);
}
*/

int main()
{
    vector<string> arr={"applejuice","applepie","apple"};
    int n=3;
    cout<<longestCommonPrefix(arr,n);
    return 0;
}

