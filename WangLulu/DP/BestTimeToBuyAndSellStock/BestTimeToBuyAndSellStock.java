package DP.BestTimeToBuyAndSellStock;

public class BestTimeToBuyAndSellStock {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int[][]dp = new int [n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i = 1;i<n;i++){
            dp[i][0] = Math.max(dp[i-1][0],dp[i-1][1]+prices[i]);
            dp[i][1] = Math.max(dp[i-1][1],-prices[i]);//只进行一次交易
        }
        return dp[n-1][0];
    }
    //贪心算法
    public int maxProfitv2(int[] prices) {
        int n = prices.length;
        int min = Integer.MAX_VALUE;
        int ans = 0;
        for(int i = 0;i<n;i++){
            if(prices[i]<min){
                min = prices[i];
            }else{
                ans = Math.max(ans,prices[i]-min);
            }
        }
        return ans;
    }
}
