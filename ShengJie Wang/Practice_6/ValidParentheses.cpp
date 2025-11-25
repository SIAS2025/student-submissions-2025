class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2)    return false;
        stack<char> left;
        unordered_map<char, char> map = {{')', '('}, {'}', '{'}, {']', '['}};

        for(auto c : s){
            cout<<c<<endl;
            if(map.find(c) == map.end())
                left.push(c);
            else if(!left.empty() && map[c] == left.top())
                left.pop();
            else
                return false;
        }
        return left.empty();
    }
};