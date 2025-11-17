public class PrefectSquaresSimple {
    public int numSquares(int n) {
        int[] dp = new int[n + 1];
        for(int i = 1;i < (int)Math.sqrt(n) + 1;i++) {
            dp[i * i] = 1;
        }
        for(int i = 1;i < n + 1;i++) {
            if(dp[i] == 0) {
                dp[i] = Integer.MAX_VALUE;
                for(int j = 1;i - j * j >= 0;j++) {
                    dp[i] = Math.min(dp[i],dp[i - j * j] + 1);
                }
            }
        }
        return dp[n];
    }
}
