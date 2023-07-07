#include<bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode* children[26];
    int childCount;
    bool isTerminal;

    TrieNode(char ch)
    {
        data=ch;
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        childCount=0;
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
            root->childCount++;
        }
        InsertUtil(root->children[word[0]-'a'],word.substr(1));
    }

    void Insert(string word)
    {
        InsertUtil(root,word);
    }

    bool SearchWordUtil(TrieNode* root,string word)
    {
        if(word.size()==0){return root->isTerminal;}
        if(root->children[word[0]-'a']==NULL){return false;}
        return SearchWordUtil(root->children[word[0]-'a'],word.substr(1));
    }

    bool SearchWord(string word)
    {
        return SearchWordUtil(root,word);
    }

    void DeleteUtil(TrieNode* parent,TrieNode* child,string word)
    {
        if(child->childCount==0&&child->isTerminal==false)
        {
            parent->children[word[0]-'a']=NULL;
            parent->childCount--;
            delete child;
        }

        if(word.size()==1){return;}

        DeleteUtil(child,child->children[word[1]-'a'],word.substr(1));
    }

    void Delete(string word)
    {
        if(SearchWord(word)==false){return;}
        TrieNode* temp=root;

        for(auto it:word)
        {
            temp=temp->children[it-'a'];
        }
        temp->isTerminal=false;

        DeleteUtil(root,root->children[word[0]-'a'],word);
    }
};

int main()
{
    Trie t;
    t.Insert("alpha");
    t.Insert("alp");
    t.Insert("alpin");
    t.Insert("alphar");

    cout<<::boolalpha<<t.SearchWord("alpha")<<endl;
    t.Delete("alpha");
    cout<<::boolalpha<<t.SearchWord("alpha")<<endl;

    cout<<::boolalpha<<t.SearchWord("alp")<<endl;
    t.Delete("alp");
    cout<<::boolalpha<<t.SearchWord("alp")<<endl;

    cout<<::boolalpha<<t.SearchWord("alpin")<<endl;
    t.Delete("alpin");
    cout<<::boolalpha<<t.SearchWord("alpin")<<endl;

    cout<<::boolalpha<<t.SearchWord("alphar")<<endl;
    t.Delete("alphar");
    cout<<::boolalpha<<t.SearchWord("alphar")<<endl;

    return 0;
}

