class Solution {
public:
    static long long maximumSubarraySum(vector<int>& nums, int k) {
        const int n=nums.size();
        bitset<100001> in_arr=0;
        long long sum=0, maxSum=0;
        // sliding window
        for( int l=0, r=0, len=0; r<n; r++){
            int x=nums[r];
            sum+=x;
            while (l<r && ( len>k-1 || in_arr[x])) {
                in_arr[nums[l]]=0;
                sum-=nums[l];
                l++;
                len--;
            }
            in_arr[x]=1;
            len++;
            if (len==k) maxSum=max(maxSum, sum);
        }
        return maxSum;
    }
};



auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();