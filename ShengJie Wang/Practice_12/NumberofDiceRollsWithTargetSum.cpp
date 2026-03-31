class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n * k) {
            return 0;
        }
        vector<int> sum_last(target + 1, 0);

        for (int m = 1; m <= k && m <= target; m++) {
            sum_last[m] = 1;
        }
        for (int l = 2; l <= n; l++) {              //第几个筛子
            vector<int> sum_cur(target + 1, 0);
            for (int i = 1; i <= k; i++) {          //当前筛子的可能点数
                for (int j = l - 1; j < target; j++) {  //前几个筛子的和
                    int temp = i + j;
                    if (temp <= target) {
                        sum_cur[temp] = (sum_cur[temp] + sum_last[j]) % 1000000007;
                    } else {
                        break;
                    }
                }
            }
            sum_last = move(sum_cur);
        }
        return sum_last[target];
    }
};