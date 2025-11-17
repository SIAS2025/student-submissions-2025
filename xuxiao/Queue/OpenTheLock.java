import java.util.ArrayDeque;
import java.util.Queue;

public class OpenTheLock {
    public int openLock(String[] deadends, String target) {
        Queue<String> queue = new ArrayDeque<>();
        ArrayDeque<String> dead = new ArrayDeque<>();
        int step = 0;
        for (String deadend : deadends) {
            dead.add(deadend);
        }
        queue.add("0000");
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String curr = queue.remove();
                if (curr.equals(target)) {
                    return step;
                }
                if (dead.contains(curr)) {
                    continue;
                }
                dead.add(curr);
                for (int j = 0; j < 4; j++) {
                    String up = curr.substring(0, j) + (curr.charAt(j) == '9' ? '0' : (char) (curr.charAt(j) + 1)) + curr.substring(j + 1);
                    String down = curr.substring(0, j) + (curr.charAt(j) == '0' ? '9' : (char) (curr.charAt(j) - 1)) + curr.substring(j + 1);
                    queue.add(up);
                    queue.add(down);
                }
            }
            step++;
        }
        return -1;
    }
}
