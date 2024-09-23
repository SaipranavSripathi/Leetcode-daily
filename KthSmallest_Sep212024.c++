class Solution {
public:
    int findKthNumber(int n, int k) {
        int current = 1;
        k=k-1;  // Decrement k to handle zero-based indexing
        
        while (k > 0) {
            int count = countNumbersWithPrefix(current, n);
            if (k >= count) {
                current++;  // Move to the next prefix
                k -= count;
            } else {
                current *= 10;  // Go deeper in the current prefix
                --k;
            }
        }
        
        return current;
    }

private:
    int countNumbersWithPrefix(int prefix, int n) {
        long long firstNumber = prefix, nextNumber = prefix + 1;
        int totalCount = 0;

        while (firstNumber <= n) {
            totalCount += static_cast<int>(min((long long)n + 1, nextNumber) - firstNumber);
            firstNumber *= 10;
            nextNumber *= 10;
        }

        return totalCount;
    }
};