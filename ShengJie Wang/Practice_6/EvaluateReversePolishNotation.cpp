class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for(auto &token : tokens){
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int num1 = nums.top(); nums.pop();
                int num2 = nums.top(); nums.pop();
                
                if(token == "+") nums.push(num2 + num1);
                else if(token == "-") nums.push(num2 - num1);
                else if(token == "*") nums.push(num2 * num1);
                else nums.push(num2 / num1);
            }
            else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};