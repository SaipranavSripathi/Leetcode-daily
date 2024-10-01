class Solution {
public:
    static bool canArrange(vector<int>& arr, int k) {
        vector<int> freq(k, 0);
        for(int x: arr){
            x%=k;
            if (x<0) x+=k;
            freq[x]++;
        }

        if (k%2==0 && freq[k/2]%2!=0) return 0;
        int k2=k/2-(k%2==0);
        for(int i=1; i<=k2; i++)
            if (freq[i]!=freq[k-i]) return 0;
        return 1;
    }
};