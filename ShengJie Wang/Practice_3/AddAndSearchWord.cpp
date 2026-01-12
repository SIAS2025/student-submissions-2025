/* Add and Search Word - Data structure design */

struct TrieNode{
    TrieNode* nexts[26];
    bool endby;
    TrieNode(){
        fill(nexts, nexts + 26, nullptr);
        endby = false;
    }
};

class Trie{
public:
    Trie(){
        root = new TrieNode();
    }
    void Insert(string word){
        TrieNode* cur = root;
        for(char c : word){
            int index = c - 'a';
            if(!cur->nexts[index])
                cur->nexts[index] = new TrieNode();
            cur = cur->nexts[index];
        }
        cur->endby = true;
    }
    
    TrieNode* root;
};

class WordDictionary {
Trie Dictionary;
bool _search(string word, int start, TrieNode* root) {
    if(start == word.size())
        return root ? root->endby : false;
    if(word[start] == '.'){
        for(int i = 0; i < 26; i++){
            if(!root->nexts[i])
                continue;
            if(_search(word, start + 1, root->nexts[i]))
                return true;
        }
    }
    else{
        int index = word[start] - 'a';
        if(!root->nexts[index])
            return false;
        if(_search(word, start + 1, root->nexts[index]))
            return true;
    }
    return false;
}
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        Dictionary.Insert(word);
    }
    
    bool search(string word) {
        return _search(word, 0, Dictionary.root);
    }
};
