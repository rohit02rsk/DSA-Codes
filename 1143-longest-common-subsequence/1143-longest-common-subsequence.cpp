class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text2.size()+1, vector<int>(text1.size()+1, 0));
        
        for(int i=1; i<dp.size(); i++) {
            for(int j=1; j<dp[0].size(); j++) {
                if(text2[i-1] == text1[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[text2.size()][text1.size()];
    }
};