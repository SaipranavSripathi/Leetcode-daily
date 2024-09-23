class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        set<string> st(dictionary.begin(), dictionary.end());
        int n = s.length();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < i; j++) {
                string str = s.substr(j, i - j);
                if (st.find(str) != st.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }
        return dp[n];
    }
};