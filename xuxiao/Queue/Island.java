import java.util.ArrayDeque;
import java.util.LinkedList;
import java.util.Queue;

public class Island {
    public int numIslands(char[][] grid) {
        int sum = 0;
        Queue<Integer[]> queue = new ArrayDeque<>();
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == '1') {
                    queue.add(new Integer[]{i,j});
                    sum++;
                    while (!queue.isEmpty()) {
                        Integer[] curr = queue.remove();
                        int x = curr[0];
                        int y = curr[1];
                        if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length || grid[x][y] == '0') {
                            continue;
                        }
                        grid[x][y] = '0';
                        queue.add(new Integer[]{x + 1,y});
                        queue.add(new Integer[]{x - 1,y});
                        queue.add(new Integer[]{x,y + 1});
                        queue.add(new Integer[]{x,y - 1});
                    }
                }

            }
        }
        return sum;
    }
}
