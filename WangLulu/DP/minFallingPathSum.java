public class minFallingPathSum {
    public int solution(int[][] matrix) {
        int n = matrix.length;
        int[][]dp = new int[n+1][n+1];
        dp[0][0] = matrix[0][0];
        for(int i = 0 ;i < n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++){
            for(int j = 0;j<n;j++){
                if(j == 0){
                    dp[i][j] = Math.min(dp[i-1][j],dp[i-1][j+1])+matrix[i][j];
                }else if(j == n-1){
                    dp[i][j] = Math.min(dp[i-1][j],dp[i-1][j-1])+matrix[i][j];
                }else {
                    dp[i][j] = Math.min(Math.min(dp[i-1][j],dp[i-1][j-1]),dp[i-1][j+1])+matrix[i][j];
                }
                
            }
        }
        int ans = dp[n-1][0];
        for(int i = 1;i<n;i++){
            ans = Math.min(ans,dp[n-1][i]);
        }
        return ans;
    }
}
