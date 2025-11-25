package Stack;

import java.util.Stack;

public class EvaluateReversePolishNotations {
     public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String s : tokens) {
            if (isNumber(s)) {
                stack.push(Integer.parseInt(s));
            } else {
                int i = stack.pop();
                int j = stack.pop();
                switch (s) {
                    case "+":
                        stack.push(j + i);
                        break;
                    case "-":
                         stack.push(j-i);
                         break;
                    case "*":
                        stack.push(j*i);
                        break;
                    case "/":
                        stack.push(j/i);
                        break;
                }
            }
        }
        return stack.pop();
    }
    public boolean isNumber(String s){
        if(s.equals("+")||s.equals("-")||s.equals("*")||s.equals("/")){
            return false;
        }else{
            return true;
        }
    }
    
}
