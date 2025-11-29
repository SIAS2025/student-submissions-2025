package Queue;

import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;

public class PerfectSquares {
    public int numSquares(int n) {
        Queue<Integer> queue = new LinkedList<>();
        HashSet<Integer> visited = new HashSet<>();
        int step = 0;
        queue.offer(n);
        visited.add(n);
        while (!queue.isEmpty()) {
            step++;
            int x = queue.size();
            for (int i = 0; i < x; i++) {
                int cur = queue.poll();
                for (int j = 1; j * j <= cur; j++) {
                    int temp = cur - j * j;
                    if (temp == 0) {
                        return step;
                    }
                    if (!visited.contains(temp)) {
                        visited.add(temp);
                        queue.offer(temp);
                    }

                }
            }
        }
        return step;
    }
}
