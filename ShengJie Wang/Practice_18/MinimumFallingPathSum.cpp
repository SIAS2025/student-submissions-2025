class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;
        for(int i = 1; i <= row; ++i){
            for(int j = 0; j <= col; ++j){
                int _min = min(matrix[i - 1][j], min(j == 0 ? 10001 : matrix[i - 1][j - 1], j == col ? 10001 : matrix[i - 1][j + 1]));
                matrix[i][j] += _min;
            }
        }
        return *min_element(matrix[row].begin(), matrix[row].end());
    }
};