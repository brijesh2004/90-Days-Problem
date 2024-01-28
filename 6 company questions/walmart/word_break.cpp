class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictSet;  // Use unordered_set for faster lookups
    for (const string& word : wordDict) {
        dictSet.insert(word);
    }
    
    int n = s.size();
    // dp[i] will be true if s[0:i-1] can be segmented into words
    vector<bool> dp(n + 1, false);
    dp[0] = true;  // Empty string is always breakable
    
    for (int i = 1; i <= n; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            // Check if the substring s[j:i-1] is in the dictionary
            if (dp[j] && dictSet.find(s.substr(j, i - j)) != dictSet.end()) {
                dp[i] = true;
                break;
            }
        }
    }
    
    return dp[n];
    }
};