package DP;

import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class WordBreak {
        public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean [] dp = new boolean [n+1];
        Arrays.fill(dp,false);
        Set<String> set = new HashSet<>();
        for(String word : wordDict){
            set.add(word);
        } 
        dp[0] = true;
        for(int i = 1;i<=n;i++){
            for(int j = 0;j<i;j++){
                String seg = s.substring(j,i);
                if(dp[j]&&set.contains(seg)){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
