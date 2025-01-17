class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans ^= derived[i];
        }
        if(ans == 0)return true;
        return false;
    }
};