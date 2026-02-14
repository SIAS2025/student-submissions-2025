package DP.BestTimeToBuyAndSellStock;

public class BestTimeToBuyAndSellStockIV {
    public int maxProfit(int k, int[] prices) {
        int n = prices.length;
        k = Math.min(k,n/2);//完成的交易次数--一买一卖
        int[][][]dp = new int[n][2][k+1];
        for(int i =0;i<=k;i++){
            dp[0][0][i] = 0;
            dp[0][1][i] = -prices[0];
        }
        for(int i = 1;i<n;i++){
            for(int j = 1;j<=k;j++){
                dp[i][0][j] = Math.max(dp[i-1][0][j],dp[i-1][1][j]+prices[i]);
                dp[i][1][j] = Math.max(dp[i-1][1][j],dp[i-1][0][j-1]-prices[i]);
            }
        }
        return dp[n-1][0][k];
    }
}
