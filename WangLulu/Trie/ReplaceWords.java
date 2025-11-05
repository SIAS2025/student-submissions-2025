package Trie;

import java.util.List;

public class ReplaceWords {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for(String root:dictionary){
            trie.insert(root);
        }
        String[] words = sentence.split(" ");
        for(int i = 0 ;i<words.length;i++){
            String shortestRoot = trie.find(words[i]);
            if(shortestRoot!=null){
                words[i] = shortestRoot;
            }
        }
        return String.join(" ",words);
    }
}
class TrieNode{
    TrieNode[] children = new TrieNode[26];
    boolean isRoot;
    public TrieNode(){
        isRoot = false;
    }
}
class Trie{
    private TrieNode root;
    public Trie(){
        root = new TrieNode();
    }
    public void insert(String rootword){
        TrieNode cur = root;
        for(char c :rootword.toCharArray()){
            int index = c -'a';
            if(cur.children[index] == null){
                cur.children[index] = new TrieNode();
            }
            cur = cur.children[index];
        }
        cur.isRoot = true;
    }
    public String find(String words){
        TrieNode cur = root;
        StringBuilder sb = new StringBuilder();
        for(char c :words.toCharArray()){
            int index = c - 'a';
            if(cur.children[index] == null){
                break;
            }
            cur = cur.children[index];
            sb.append(c);
            if(cur.isRoot){
                return sb.toString();
            }
        }
        return null;
    }
}
