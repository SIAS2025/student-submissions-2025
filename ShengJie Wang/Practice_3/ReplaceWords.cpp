/* Replace Words */

struct TrieNode{
    TrieNode* nexts[26];
    int endby;
    TrieNode(){
        fill(nexts, nexts + 26, nullptr);
        endby = 0;
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
    
    string find(string word){
        string ans;
        TrieNode* cur = root;
        for(char c : word){
            int index = c - 'a';
            if(!cur->nexts[index])
                return word;
            ans += c;
            cur = cur->nexts[index];
            if(cur->endby)
                return ans;
        }
        return word;
    }
    TrieNode* root;
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie Dictionary;
        string ans;
        for(string word : dictionary){
            Dictionary.Insert(word);
        }
        TrieNode* cur = Dictionary.root;
        string word;
        for(char c : sentence){
            if(c == ' '){
                if(!word.empty())
                    ans += Dictionary.find(word) + ' ';
                word.clear();
                continue;
            }
            word += c;
        }
        if(!word.empty())
            ans += Dictionary.find(word);
        return ans;
    }
};