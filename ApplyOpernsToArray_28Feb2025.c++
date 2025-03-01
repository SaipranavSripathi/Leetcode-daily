class Solution {
    public:
        vector<int> applyOperations(vector<int>& nums) {
            int n = nums.size();
    
            // Step 1: Apply operations on the array
            for (int index = 0; index < n - 1; index++) {
                if (nums[index] == nums[index + 1] && nums[index] != 0) {
                    nums[index] *= 2;
                    nums[index + 1] = 0;
                }
            }
    
            // Step 2: Shift non-zero elements to the beginning
            int nonZeroIndex = 0;
            for (int iterateIndex = 0; iterateIndex < n; iterateIndex++) {
                if (nums[iterateIndex] != 0) {
                    nums[nonZeroIndex++] = nums[iterateIndex];
                }
            }
    
            // Step 3: Fill the remaining positions with zeros
            while (nonZeroIndex < n) {
                nums[nonZeroIndex++] = 0;
            }
    
            return nums;
        }
    };