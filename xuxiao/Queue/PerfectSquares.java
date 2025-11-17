public class PerfectSquares {
    /**
     *时间很长
     */
    public int numSquares(int n) {
        int max = (int)Math.sqrt(n);
        if(max * max == n) {
            return 1;
        }
        int[] dp = new int[max + 1];
        for(int i = 1;i < max + 1;i++) {
            dp[i] = i * i;
        }
        return numSquares2(n,dp);

    }
    public int numSquares2(int n,int[] dp) {
        if(n ==  0) {
            return 0;
        }
        int min = Integer.MAX_VALUE;
        for(int i = 1;i <= dp.length - 1;i++) {
            if(n >= dp[i]) {
                min = Math.min(min,numSquares2(n - dp[i], dp) + 1);
            }
        }
        return min;
    }
    public static void main(String[] args) {
        PerfectSquares ps = new PerfectSquares();
        System.out.println(ps.numSquares(533));
    }
}
