import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;

public class MapSumPair {
    static class MapSum {
        private TireNode root;
        static private HashMap<String,Integer> list = new HashMap<>();
        class TireNode{
            TireNode[] children = new TireNode[26];
            int sum = 0;
        }
        public MapSum() {
            root = new TireNode();
        }

        public void insert(String key, int val) {
            TireNode cur = root;
            if(list.containsKey(key)) {
                for (int i = 0; i < key.length(); i++) {
                    if(cur.children[key.charAt(i) - 'a'] == null) {
                        cur.children[key.charAt(i) - 'a'] = new TireNode();
                    }
                    cur = cur.children[key.charAt(i) - 'a'];
                    cur.sum -= list.get(key);
                    cur.sum += val;
                }
                list.put(key, val);
            }else {
                list.put(key, val);
                for (int i = 0; i < key.length(); i++) {
                    if (cur.children[key.charAt(i) - 'a'] == null) {
                        cur.children[key.charAt(i) - 'a'] = new TireNode();
                    }
                    cur = cur.children[key.charAt(i) - 'a'];
                    cur.sum += val;
                }
            }

        }

        public int sum(String prefix) {
            TireNode cur = root;
            for (int i = 0; i < prefix.length(); i++) {
                if(cur.children[prefix.charAt(i) - 'a'] == null) {
                    return 0;
                }
                cur = cur.children[prefix.charAt(i) - 'a'];
            }
            return cur.sum;
        }
    }
    public static void main(String[] args) {
        MapSum mapSum = new MapSum();

        // 插入键值对
        mapSum.insert("apple", 3);
        System.out.println(mapSum.sum("ap")); // 输出 3

        mapSum.insert("app", 2);
        System.out.println(mapSum.sum("ap")); // 输出 5，因为 apple(3) + app(2) = 5

        mapSum.insert("apple", 2);
        System.out.println(mapSum.sum("ap")); // 输出 4，因为 apple更新为2, app=2, 共4
    }
}
