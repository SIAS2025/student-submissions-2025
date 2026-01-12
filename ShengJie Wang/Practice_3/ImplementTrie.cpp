
/*  Implement Trie (Prefix Tree) */

struct TrieNode{
    TrieNode* nexts[26];
    bool endby;
    TrieNode(){
        fill(nexts, nexts + 26, nullptr);
        endby = false;
    }
};
class Trie {
TrieNode* root;
TrieNode* scan(string str, bool do_insert){
    TrieNode* cur = root;
    for(char c : str){
        int index = c - 'a';
        if(!cur->nexts[index]){
            if(!do_insert)
                return nullptr;
            else
                cur->nexts[index] = new TrieNode();
        }
        cur = cur->nexts[index];
    }
    return cur;
}
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* ret = scan(word, 1);
        ret->endby = true;
    }
    
    bool search(string word) {
        TrieNode* ret = scan(word, 0);
        return ret ? ret->endby : false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* ret = scan(prefix, 0);
        return ret ? true : false;
    }
};
