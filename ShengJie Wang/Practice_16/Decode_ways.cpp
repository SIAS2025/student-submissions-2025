class Solution {
public:
    int numDecodings(string s) {
        if(s[0] == '0'){
            return 0;
        }
        int last = 1;
        int cur = 1;
        for(int i = 1; i < s.size(); ++i){
            int new_cur =(s[i] != '0' ? cur : 0) + (s[i - 1] == '1' || s[i - 1] == '2' && s[i] < '7' ? last : 0);
            last = cur;
            cur = new_cur;
        }
        return cur;
    }
};