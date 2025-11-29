class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int len = temperatures.size();
        vector<int> ans(len, 0);
        stack<int> dt;
        for(int i = 0; i < len; i++){
            while(!dt.empty() && temperatures[i] > temperatures[dt.top()]){
                ans[dt.top()] = i - dt.top();
                dt.pop();
            }
            dt.push(i);
        }
        return ans;
    }
};