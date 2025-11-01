#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
//使用两个哈希表来存储 键值对 和 前缀和
class MapSum {
public:
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int num=val;
        if(map.count(key)!=0)
        {
            num=val-map[key];
        }
        map[key]=val;
        for(int i=0;i<=key.size();i++)
        {
            premap[key.substr(0,i)]+=num;
        }
    }
    
    int sum(string prefix) {
        return premap[prefix];
        
    }
private:
    unordered_map<string,int> map;//存放键值对
    unordered_map<string,int> premap;//存放键 前缀和 对
};



//师娘的方法
class Trienode{
public:
    vector<Trienode*> children;
    int valsum;
    Trienode():children(26,nullptr),valsum(0){}
};

class MapSum {
private:
    unordered_map<string,int> map;
    Trienode* root;
public:
    MapSum() {
        root= new Trienode();
    }
    
    void insert(string key, int val) {
        int old=map.count(key) ? map[key]:0;
        Trienode* node = root;
        for(auto ch:key)
        {
            int index=ch-'a';
            if(node->children[index]==nullptr)
            {
                node->children[index] = new Trienode();
            }
            node=node->children[index];
            node->valsum-=old;
            node->valsum+=val;
        }
        map[key] = val;
    }
    
    int sum(string prefix) {
        Trienode* node=root;
        for(auto ch : prefix)
        {
            int index=ch-'a';
            if(node->children[index]==nullptr) return 0;
            node=node->children[index];
        }
        return node->valsum;
        
    }
    ~MapSum(){
        delete root;
    }
};