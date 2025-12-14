#include <vector>
#include <stack>
using namespace std;


//单调栈解法
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty()) return vector<int> ();
        int size=temperatures.size();
        vector<int> res(size);
        stack<int> st;
        for(int i=0;i<size;i++)
        {
            //栈为空 或者  栈顶元素大于当前元素 入栈
            if(st.empty() || temperatures[st.top()]>=temperatures[i])
            {
                st.push(i);
            }
            else
            {
                while(!st.empty() && temperatures[st.top()]<temperatures[i])
                {
                    int j=st.top();
                    st.pop();
                    res[j]=i-j;
                }
                st.push(i);
            }
        }
        return res;
    }
};

//暴力解法
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        if(temperatures.empty()) return vector<int> ();
        vector<int> res;
        int size=temperatures.size();
        res.resize(size);
        for(int i=0 ; i<size-1 ; i++)
        {
            int num=0;
            for(int j=i+1 ; j<size ; j++)
            {
                if(temperatures[j]>temperatures[i])
                {
                    num=j-i;
                    break;
                }
            }
            res[i]=num;
        }
        res[size-1]=0;
        return res;
    }
};