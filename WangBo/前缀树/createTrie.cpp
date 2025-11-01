#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;


class Trie {
private:
    vector<Trie*> children;//前缀树的每个节点都有一个数组,最多存放26个孩子节点
    bool is_end;//用来指示这个节点是不是最后一级孩子节点
public:
    Trie() : children(26, nullptr), is_end(false) {
        // 现在 vector 已经有26个nullptr元素了
    }
    
    void insert(string word) {
        Trie* node = this;
        for(auto ch : word)
        {
            int index=ch-'a';
            if(node->children[index]==nullptr)
            {
                node->children[index] = new Trie();
            }
            node = node->children[index];
        }
        node->is_end=true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(auto ch : word)
        {
            int index=ch-'a';
            if(node->children[index]==nullptr)
            {
                return false;
            }
            node=node->children[index];
        }
        if(node->is_end==true) return true;
        return false;
        
    }
    
    bool startsWith(string prefix) {
        Trie* node=this;
        for(auto ch : prefix)
        {
            int index=ch-'a';
            if(node->children[index]==nullptr)
            {
                return false;
            }
            node=node->children[index];
        }
        return true;
    }
};