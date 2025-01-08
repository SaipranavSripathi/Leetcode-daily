class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        // Step 1: Iterate through each pair of words
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                string& str1 = words[i];
                string& str2 = words[j];

                // Step 2: Skip if the first string is larger than the second
                if (str1.size() > str2.size()) continue;

                // Step 3: Check if str1 is both the prefix and suffix of str2
                if (str2.find(str1) == 0 &&
                    str2.rfind(str1) == str2.size() - str1.size()) {
                    ++count;
                }
            }
        }

        // Step 4: Return the total count of prefix-suffix pairs
        return count;
    }
};