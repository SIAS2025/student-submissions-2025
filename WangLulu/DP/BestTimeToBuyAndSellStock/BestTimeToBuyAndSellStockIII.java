package DP.BestTimeToBuyAndSellStock;

public class BestTimeToBuyAndSellStockIII {
        public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][][]dp = new int [n][2][3];
        for(int i = 0;i<=2;i++){
            dp[0][0][i] = 0;
            dp[0][1][i] = -prices[0];
        }
        for(int i = 1;i<n;i++){
            for(int j = 1;j<=2;j++){
                dp[i][0][j] = Math.max(dp[i-1][0][j],dp[i-1][1][j]+prices[i]);
                dp[i][1][j] = Math.max(dp[i-1][1][j],dp[i-1][0][j-1]-prices[i]);
            }
        }
        return dp[n-1][0][2];
    }
}
