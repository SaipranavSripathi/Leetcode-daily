class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        while(k--) *min_element(begin(nums), end(nums)) *= multiplier;
        return nums;
    }
};