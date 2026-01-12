/* Map Sum Pairs */
struct TrieNode{
    TrieNode* nexts[26];
    int val;
    int sum_val;
    TrieNode(){
        fill(nexts, nexts + 26, nullptr);
        val = 0;
        sum_val = 0;
    }
};
class MapSum {
TrieNode* root; 
TrieNode* scan(bool do_insert, string str, int val = 0){
    TrieNode* cur = root;
    for(char c : str){
        int index = c - 'a';
        if(!cur->nexts[index]){
            if(do_insert)
                cur->nexts[index] = new TrieNode();
            else
                return nullptr;
        }
        if(do_insert)
            cur->sum_val += val;
        cur = cur->nexts[index];
    }
    return cur;
}
public:
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int add = val;
        TrieNode* ret = scan(false, key);
        if(ret && ret->val)
            add = val - ret -> val;
        ret = scan(true, key, add);
        ret->sum_val += add;
        ret->val = val;
    }
    
    int sum(string prefix) {
        TrieNode* ret = scan(false, prefix);
        return ret ? ret -> sum_val : 0;
    }
};
