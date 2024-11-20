class Solution {
public:
    int takeCharacters(string s, int k) {
        if (k == 0) return 0;
        
        vector<int> cntr(3, 0);
        for (char c : s) cntr[c - 'a']++;
        
        for (int i = 0; i < 3; i++) {
            if (cntr[i] < k) return -1;
        }
        
        int n = s.size();
        vector<int> window(3, 0);
        vector<int> need(3);
        for (int i = 0; i < 3; i++) {
            need[i] = cntr[i] - k;
        }
        
        int left = 0, maxLen = 0;
        for (int right = 0; right < n; right++) {
            window[s[right] - 'a']++;
            while (window[0] > need[0] || 
                   window[1] > need[1] || 
                   window[2] > need[2]) {
                window[s[left] - 'a']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        
        return n - maxLen;
    }
};