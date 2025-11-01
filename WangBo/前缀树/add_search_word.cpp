#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <memory>
using namespace std;


class Treenode{
public:
    bool isend;
    vector<unique_ptr<Treenode>> next;
    Treenode():isend(false),next(26){}
    void addWord(const string &str)
    {
        Treenode* node=this;
        for(char ch:str)
        {
            int index=ch-'a';
            if(!node->next[index])
            {
                node->next[index]=make_unique<Treenode>();
            }
            node=node->next[index].get();
        }
        node->isend=true;
    }
    bool search(const string &str,int start)
    {
        Treenode* node=this;
        for(int i=start;i<str.size();i++)
        {
            int index= str[i]-'a';
            if(str[i]=='.')
            {
                for(int j=0;j<26;j++)
                {
                    if(node->next[j] && node->next[j]->search(str,i+1)) return true;
                }
                return false;
            }
            else
            {
                if(!node->next[index])  return false;
                node=node->next[index].get();
            }  
        }
        return node->isend;
    }

};

class WordDictionary {
public:
    unique_ptr<Treenode> root;
    WordDictionary() {
        root=make_unique<Treenode>();
    }
    
    void addWord(string word) {
        root->addWord(word);
    }
    
    bool search(string word) {
        return root->search(word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */