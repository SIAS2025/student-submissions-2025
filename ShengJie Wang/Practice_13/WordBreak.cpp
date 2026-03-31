class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        for (int i = 0; i < s.size(); i++) {
            if (!dp[i]) {
                continue;
            }
            for (auto& word : wordDict) {
                int match_to = i + word.size();
                if (match_to <= s.size()) {
                    dp[match_to] = dp[match_to] || match(s, i, word);
                }
            }
            
        }
        return dp[s.size()];
    }

    bool match(string& s, int start, string& word) {
        if (start + word.size() - 1 > s.size()) {
            return false;
        }

        for(int i = 0; i < word.size(); i++) {
            if(s[start + i] != word[i]) {
                return false;
            }
        }
        return true;
    }

};