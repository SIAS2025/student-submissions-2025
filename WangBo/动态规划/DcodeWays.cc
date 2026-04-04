class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        dp[0]=1;        
        for(int i=1 ; i<=s.size() ; i++)
        {
            //第i个数单独编码 dp[i]=dp[i-1],前提是s[i]!=0
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            //i和i-1联合编码,dp[i]=dp[i-2],前提是s[i-1]s[i]<26 且 s[i-1]!=0
            if(i>1 && s[i-2]!='0' && ((static_cast<int>(s[i-2]-'0'))*10+static_cast<int>(s[i-1]-'0')<=26)){
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.size()];

    }
};