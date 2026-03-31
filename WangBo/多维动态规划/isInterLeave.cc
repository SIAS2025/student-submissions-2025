#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size(), k = s3.size();
        if (m + n != k) return false;

        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        // 初始化第一列：只用 s1
        for (int i = 1; i <= m; ++i) {
            dp[i][0] = dp[i-1][0] && (s1[i-1] == s3[i-1]);
        }

        // 初始化第一行：只用 s2
        for (int j = 1; j <= n; ++j) {
            dp[0][j] = dp[0][j-1] && (s2[j-1] == s3[j-1]);
        }

        // 填充 DP 表
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                // 尝试从 s1 取一个字符
                if (s1[i-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j];
                }
                // 尝试从 s2 取一个字符
                if (s2[j-1] == s3[i+j-1]) {
                    dp[i][j] = dp[i][j] || dp[i][j-1];
                }
            }
        }

        return dp[m][n];
    }
};