

class Solution {
public:
    int numSquares(int n) {       
        vector<int> f(n + 1);
        for(int i = 1; i <= n; i++){
            int n_min = INT_MAX;
            for(int j = 1; j * j <= i; j++){
                n_min = min(n_min, f[i - j * j]);
            }
            f[i] = n_min + 1;
        }
        return f[n];
    }
};