class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        // Get lengths of arrays
        int len1 = nums1.size();
        int len2 = nums2.size();

        // Map to store frequency of each number
        unordered_map<int, long> freq;

        // Add frequencies for nums1 elements
        // Each element appears len2 times in final result
        for (int num : nums1) {
            freq[num] += len2;
        }

        // Add frequencies for nums2 elements
        // Each element appears len1 times in final result
        for (int num : nums2) {
            freq[num] += len1;
        }

        // XOR numbers that appear odd number of times
        int ans = 0;
        for (auto& [num, count] : freq) {
            if (count % 2 == 1) {
                ans ^= num;
            }
        }

        return ans;
    }
};