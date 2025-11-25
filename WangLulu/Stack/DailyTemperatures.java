package Stack;

import java.util.Deque;
import java.util.LinkedList;

public class DailyTemperatures {
        public int[] dailyTemperatures(int[] temperatures) {
        Deque<Integer> stack = new LinkedList<>();
        int n = temperatures.length;
        int[] result = new int[n];
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]) {
                int x = stack.pop();
                result[x] = i - x;
            }
            stack.push(i);
        }
        return result;
    }
}
