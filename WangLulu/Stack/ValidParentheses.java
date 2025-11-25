package Stack;

import java.util.Stack;

public class ValidParentheses {
    public boolean isValid(String s) {
        if (s.isEmpty()) {
            return true;
        }
        Stack<Character> stack = new Stack<>();
        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) {
                    return false;
                }
                char x = stack.pop();
                if ((c == ')' && x != '(') || (c == '}' && x != '{') || (c == ']' && x != '[')) {
                    return false;
                }

            }

        }
        return stack.isEmpty();
    }
    
}
