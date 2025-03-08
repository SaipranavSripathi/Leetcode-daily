class Solution {
    public:
        int minimumRecolors(string blocks, int k) {
            int left = 0, numWhites = 0, numRecolors = INT_MAX;
    
            // Move right pointer
            for (int right = 0; right < blocks.size(); right++) {
                // Increment numWhites if block at right pointer is white
                if (blocks[right] == 'W') {
                    numWhites++;
                }
    
                // k consecutive elements are found
                if (right - left + 1 == k) {
                    // Update minimum
                    numRecolors = min(numRecolors, numWhites);
    
                    // Decrement numWhites if block at left pointer is white
                    if (blocks[left] == 'W') numWhites--;
    
                    // Move left pointer
                    left++;
                }
            }
            return numRecolors;
        }
    };