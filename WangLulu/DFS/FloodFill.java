package DFS;

public class FloodFill {
    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int rows = image.length;//行
        int cols = image[0].length;//列
        int original = image[sr][sc];
        if(original == color){
            return image;
        }
        dfs(image,sr,sc,original,color,rows,cols);
        return image;
    }
    public void dfs(int [][] image, int sr,int sc,int original,int color,int rows,int cols){
        if(sr<0||sr>=rows||sc<0||sc>=cols){
            return;
        }
        if(image[sr][sc]!=original){
            return;
        }
        image[sr][sc] = color;
        dfs(image,sr-1,sc,original,color,rows,cols);
        dfs(image,sr+1,sc,original,color,rows,cols);
        dfs(image,sr,sc+1,original,color,rows,cols);
        dfs(image,sr,sc-1,original,color,rows,cols);
    }
}
