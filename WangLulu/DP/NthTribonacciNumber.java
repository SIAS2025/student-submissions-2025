package DP;

import java.util.HashMap;
import java.util.Map;

public class NthTribonacciNumber {

    public int tribonacci(int n) {
        if (n == 0) {
            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        int [] dp = new int[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3;i<=n;i++){
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
    }

}
class Solution {
    Map<Integer,Integer> map = new HashMap<>();
    public int tribonacci(int n) {
        if(map.isEmpty()){
            map.put(0,0);
            map.put(1,1);
            map.put(2,1);
        }
        if(map.containsKey(n)){
            return map.get(n);
        }
        int ans = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
        map.put(n,ans);
        return ans;
    }
}
