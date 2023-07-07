#include<bits/stdc++.h>
using namespace std;

/*
vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    set<string> Set;
    for(auto it:contactList){Set.insert(it);}contactList.clear();
    for(auto it:Set){contactList.push_back(it);}

    vector<vector<string>> ans;
    int i=0;
    for(auto it:queryStr)
    {
        for(auto gt=contactList.begin();gt!=contactList.end();gt++)
        {
            string str=*gt;
            if(str[i]!=it)
            {
                auto rt=gt;
                gt--;
                contactList.erase(rt);
            }
        }
        if(contactList.size()==0){break;}
        ans.push_back(contactList);
        i++;
    }
    return ans;
}
*/

class TrieNode
{
public:

    char data;
    TrieNode* children[26];
    vector<char> charIndex;
    bool isTerminal;

    TrieNode(char ch)
    {
        data=ch;

        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }

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

    void InsertUtil(TrieNode* root,string word)
    {
        if(word.size()==0){root->isTerminal=true;return;}
        if(root->children[word[0]-'a']==NULL)
        {
            root->children[word[0]-'a']=new TrieNode(word[0]);
            root->charIndex.push_back(word[0]);
        }
        InsertUtil(root->children[word[0]-'a'],word.substr(1));
    }

    void Insert(string word)
    {
        InsertUtil(root,word);
    }

    TrieNode* PrefixEndNode(string prefix)
    {
        TrieNode* temp=root;
        for(auto it:prefix)
        {
            if(temp->children[it-'a']==NULL){return NULL;}
            temp=temp->children[it-'a'];
        }
        return temp;
    }

    void addStrings(TrieNode* root,string prefix,vector<string> &v)
    {
        if(root->isTerminal){v.push_back(prefix);}

        sort(root->charIndex.begin(),root->charIndex.end());

        for(auto it:root->charIndex)
        {
            prefix.push_back(it);
            addStrings(root->children[it-'a'],prefix,v);
            prefix.pop_back();
        }
        return;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    Trie t;
    for(auto it:contactList){t.Insert(it);}

    string prefix;
    vector<vector<string>> ans;
    for(auto it:queryStr)
    {
        prefix.push_back(it);
        TrieNode* temp=t.PrefixEndNode(prefix);
        if(temp==NULL){break;}
        vector<string> v;
        t.addStrings(temp,prefix,v);
        ans.push_back(v);
    }

    return ans;
}

int main()
{
    vector<string> contactList={"baaab","babba","aaaab","bbbba","baaab"};
    string queryStr="bbbaa";
    vector<vector<string>> ans=phoneDirectory(contactList,queryStr);

    for(auto it:ans)
    {
        for(auto gt:it)
        {
            cout<<gt<<"  ";
        }
        cout<<endl;
    }

    return 0;
}

