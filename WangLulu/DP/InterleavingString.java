package DP;

class Solution {
    public boolean isInterleave(String s1, String s2, String s3) {
        int n1 = s1.length();
        int n2 = s2.length();
        int n3 = s3.length();
        if (n3 != n1 + n2)
            return false;
        boolean[][] dp = new boolean[n1 + 1][n2 + 1];
        dp[0][0] = true;
        for (int i = 0; i < n1; i++) {
            dp[i + 1][0] = dp[i][0] && (s1.charAt(i) == s3.charAt(i));
        }
        for (int i = 0; i < n2; i++) {
            dp[0][i + 1] = dp[0][i] && (s2.charAt(i) == s3.charAt(i));
        }
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                dp[i + 1][j + 1] = (dp[i][j + 1] && (s1.charAt(i) == s3.charAt(i + j + 1)))
                        || (dp[i + 1][j] && (s2.charAt(j) == s3.charAt(i + j + 1)));
            }
        }
        return dp[n1][n2];
    }
}