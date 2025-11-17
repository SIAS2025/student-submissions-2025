package Queue;

import java.util.LinkedList;
import java.util.Queue;

public abstract class numberOfIslands {
    public int numIslands(char[][] grid) {
        if(grid == null ||grid.length ==0){
            return 0;
        } 
        int count = 0;
        int rows = grid.length;
        int cols = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int [][] dirs = {{-1,0},{0,1},{1,0},{0,-1}};
        for(int i = 0;i < rows;i++){
            for(int j =0;j< cols;j++){
                if(grid[i][j]=='1'){
                    count++;
                    queue.offer(new int [] {i,j});
                    grid[i][j] = '0';
                    while(!queue.isEmpty()){
                        int [] cur = queue.poll();
                        int x = cur[0];
                        int y = cur[1];
                        for(int[] dir:dirs){
                            int nx = x +dir[0];
                            int ny = y +dir[1];
                            if(nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1'){
                                grid[nx][ny] = '0';
                                queue.offer(new int[] {nx,ny});
                            }
                        }
                    }
                }
            }
        }
            return count;
    }


}
