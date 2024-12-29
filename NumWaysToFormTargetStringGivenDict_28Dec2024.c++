class Solution {
public:
    vector<unordered_map<char,int>> freq_index;
    int mod = 1e9+7; 
    long long dp[1000][1000];
    long long solve(string &target, int words_idx, int pos) {
        int n = target.size();
        if(pos >= n) return 1;
        if(words_idx >= freq_index.size()) return 0;
        if(dp[pos][words_idx] != -1) return dp[pos][words_idx];
        long long count = 0;
        int freq = freq_index[words_idx][target[pos]];
        if(freq > 0) {
            count = (freq * solve(target, words_idx+1, pos+1) % mod) % mod;
        }
        count = (count + solve(target, words_idx + 1,pos) % mod) % mod;
        return dp[pos][words_idx] = count;
    }
    int numWays(vector<string>& words, string target) {
        int n = words.size();
        int m = words[0].size();
        freq_index.resize(m);
        //get the freq of each character at the particular index of each word.
        for(auto &str : words) {
            for(int i = 0;i < m;i++) {
                freq_index[i][str[i]]++;
            }
        }
        memset(dp,-1,sizeof(dp));
        return solve(target , 0, 0);
    }
};