#include <bits/stdc++.h>
using namespace std;
class Trie {
public:
    struct trieNode
    {
        bool isendofword;
        trieNode* children[26]; 
    };

    trieNode* getNode()
    {
        trieNode *newNode=new trieNode();
        newNode->isendofword=false;
        for(int i=0;i<26;i++)
        {
          newNode->children[i]=NULL;
        }
        return newNode;
    }
    Trie() {
       trieNode* root=getNode();   
    }
    trieNode* root=getNode();
    void insert(string word) {
        trieNode* crawler=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL)
            {
                crawler->children[idx]=getNode();
            }
            crawler=crawler->children[idx];
        }
        crawler->isendofword=true;
    }
    
    bool search(string word) {
        trieNode *crawler=root;
        for(int i=0;i<word.size();i++)
        {
            char ch=word[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL)
            {
                return false;
            }
            crawler=crawler->children[idx];
        }
        if(crawler->isendofword==true&&crawler!=NULL){return true;}
        return false;
        
    }
    
    bool startsWith(string prefix) {
        trieNode *crawler=root;
        for(int i=0;i<prefix.size();i++)
        {
            char ch=prefix[i];
            int idx=ch-'a';
            if(crawler->children[idx]==NULL)
            {
                return false;
            }
            crawler=crawler->children[idx];
        }
        if(crawler!=NULL){return true;}
        return false;
        
    }
};
int main()
{
	cout<<0;
	return 0;
}