class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefixCommonArray(n);

        // Initialize sets to store elements from A and B
        unordered_set<int> elementsInA, elementsInB;

        // Iterate through the elements of both arrays
        for (int currentIndex = 0; currentIndex < n; ++currentIndex) {
            // Add current elements from A and B to respective sets
            elementsInA.insert(A[currentIndex]);
            elementsInB.insert(B[currentIndex]);

            int commonCount = 0;

            // Count common elements between the sets
            for (int element : elementsInA) {
                if (elementsInB.count(element)) {
                    ++commonCount;
                }
            }

            // Store the count of common elements for the current prefix
            prefixCommonArray[currentIndex] = commonCount;
        }

        // Return the final array with counts of common elements in each prefix
        return prefixCommonArray;
    }
};