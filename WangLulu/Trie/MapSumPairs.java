package Trie;
import java.util.HashMap;
import java.util.Map;

public class MapSumPairs {
    class TrieNode{
        TrieNode[] children = new TrieNode[26];
        int sum ;
        public TrieNode(){
            sum = 0;
        }
    }
    TrieNode root = new TrieNode();
    Map<String,Integer> keyMap = new HashMap<>();
    
    public void insert(String key, int val) {
        int delta = val - keyMap.getOrDefault(key,0);
        keyMap.put(key,val);
        TrieNode cur = root;
        for(char c :key.toCharArray()){
            int index = c -'a';
            if(cur.children[index] == null){
                cur.children[index] = new TrieNode();
            }
            cur = cur.children[index];
            cur.sum +=delta;
        }
        
    }
    
    public int sum(String prefix) {
            TrieNode cur = root;
            for(char c : prefix.toCharArray()){
                int index = c -'a';
                if(cur.children[index] == null){
                    return 0;
                }
                cur = cur.children[index];
            }
            return cur.sum;
    }
}


