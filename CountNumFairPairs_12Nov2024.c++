class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        long long count = 0;
        sort(nums.begin(), nums.end());

        for(int i = 0; i<n; i++){
            int left = i+1;
            auto low = lower_bound(nums.begin()+left, nums.end(), lower-nums[i])-nums.begin();
            auto high = upper_bound(nums.begin()+left, nums.end(), upper-nums[i])-nums.begin();
            count += (high-low);
        }
        return count;
    }
};