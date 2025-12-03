package DFS;

public class WordSearch {
    public boolean exist(char[][] board, String word) {
        int row = board.length;
        int cols = board[0].length;
        char[] words = word.toCharArray();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < cols; j++) {
                if (dfs(board, words, i, j, 0, row, cols)) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean dfs(char[][] board, char[] words, int i, int j, int k, int row, int cols) {
        if (i < 0 || i >= row || j < 0 || j >= cols || board[i][j] != words[k]) {
            return false;
        }
        if (k == words.length - 1) {
            return true;
        }
        board[i][j] = 0;
        boolean ans = dfs(board, words, i + 1, j, k + 1, row, cols) || dfs(board, words, i - 1, j, k + 1, row, cols)
                || dfs(board, words, i, j + 1, k + 1, row, cols) || dfs(board, words, i, j - 1, k + 1, row, cols);
        board[i][j] = words[k];
        return ans;
    }
}
