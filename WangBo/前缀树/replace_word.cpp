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
    Treenode() : isend(false),next(26){}
    void addstr(string &str)//引用传递,减少传参开销
    {
        Treenode* node=this;
        for(int i=0;i<str.size();i++)
        {
            int index=str[i] - 'a';
            if(!node->next[index])
            {
                node->next[index]=make_unique<Treenode>();
            }
            node=node->next[index].get();
        }
        node->isend=true;
        return ;
    }
    string search(string &str)
    {
        //如果一个单词是str的前缀 返回这个单词  
        //如果 找不到str 返回str
        Treenode* node=this;
        string res;
        res.reserve(str.size());//预分配内存, 节省内存
        for(int i=0;i<str.size();i++)
        {
            int index=str[i]-'a';
            if(!node->next[index])//如果没有匹配到词根
            {
                return str;
            }
            res+=str[i];
            node=node->next[index].get();
            if(node->isend) return res;
            
        }
        return str;

    }
    // ~Treenode()
    // {
    //      for(auto child: next)
    //      {if(child) delete child;}
    // }
};

class Solution {

public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        if(dictionary.size()==0) return sentence;
        Treenode*root = new Treenode();
        int n = dictionary.size();
        for (int i=0 ;i<n;i++)
        {
            root->addstr(dictionary[i]);
        }
        int right=0;
        int left=0;
        string res;
        while(left<sentence.size())
        {
            while(sentence[right]==' ') right++;
            left=right;
            while(sentence[left]!=' ' && left<sentence.size())
            {
                left++;
            }
            string str=sentence.substr(right,left-right);
            str=root->search(str);//找到返回前缀 找不到原样返回
            res=res+str+' ';
            right=left+1;
        }
        res.pop_back();
        return res;
    }
};