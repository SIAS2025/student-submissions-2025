package DP;

import java.util.HashMap;
import java.util.Map;

public class ClimbingStairs {
    public int climbStairs(int n) {
        int[] f = new int[n + 1];
        f[0] = 1;
        f[1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
}
class Solution {
    Map<Integer, Integer> map = new HashMap<>();
    public int climbStairs(int n) {
        if (map.isEmpty()) {
            map.put(0, 1);
            map.put(1, 1);
        }
         if (map.containsKey(n)) {
            return map.get(n);
        }
        int result = climbStairs(n - 1) + climbStairs(n - 2);
        map.put(n, result);
        return result;
    }
}
