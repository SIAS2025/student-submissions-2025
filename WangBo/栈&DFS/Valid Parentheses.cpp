#include <iostream>
#include <stack>
using namespace std;


class Solution {
    public:
        bool isValid(string s) {
            stack<char> st;
            for (size_t i = 0; i < s.size(); i++)
            {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    st.push(s[i]);
                }
                else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
                {
                    switch (s[i])
                    {
                    case ')':
                        if (st.empty() || st.top() != '(')
                        {
                            return false;
                        }
                        else
                        {
                            st.pop();
                        }
                        break;
                        case ']':
                        if (st.empty() || st.top() != '[')
                        {
                            return false;
                        }
                        else
                        {
                            st.pop();
                        }
                        break;
                        case '}':
                        if (st.empty() || st.top() != '{')
                        {
                            return false;
                        }
                        else
                        {
                            st.pop();
                        }
                        break;
                    default:
                        break;
                    }
                }
            }
            return st.empty();
        }
    };