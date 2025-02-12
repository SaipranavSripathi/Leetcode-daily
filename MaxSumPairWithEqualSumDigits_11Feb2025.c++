class Solution {
    public:
        int maximumSum(vector<int>& nums) {
            int result = -1;
            // Array to map digit sums to the largest element with that sum
            // (82 to cover all possible sums from 0 to 81)
            int digitMapping[82] = {};
    
            for (int element : nums) {
                int digitSum = 0;
    
                // Calculate the digit sum of the current element
                for (int currValue = element; currValue; currValue /= 10) {
                    int currDigit = currValue % 10;
                    digitSum += currDigit;
                }
    
                // Check if there is already an element with the same digit sum
                if (digitMapping[digitSum] > 0) {
                    // Update the result if the sum of the current and mapped
                    // element is greater
                    result = max(result, digitMapping[digitSum] + element);
                }
    
                // Update the mapping to store the larger of the current or previous
                // element for this digit sum
                digitMapping[digitSum] = max(digitMapping[digitSum], element);
            }
    
            return result;
        }
    };