class Solution {
public:
    vector<string> stringMatching(vector<string> &words) {
        vector<string> matchingWords;

        // Iterate through each word in the input list.
        for (int currentWordIndex = 0; currentWordIndex < words.size();
             currentWordIndex++) {
            // Compare the current word with all other words.
            for (int otherWordIndex = 0; otherWordIndex < words.size();
                 otherWordIndex++) {
                if (currentWordIndex == otherWordIndex)
                    continue;  // Skip comparing the word with itself.

                // Check if the current word is a substring of another word.
                if (isSubstringOf(words[currentWordIndex],
                                  words[otherWordIndex])) {
                    // Add it to the result list if true.
                    matchingWords.push_back(words[currentWordIndex]);
                    break;  // No need to check further for this word.
                }
            }
        }

        return matchingWords;
    }

private:
    // Helper function to check if `sub` is a substring of `main`.
    bool isSubstringOf(string &sub, string &main) {
        // Loop through possible starting indices in `main`.
        for (int startIndex = 0; startIndex < main.size(); startIndex++) {
            bool subFits = true;

            // Check if the substring matches from the current start index.
            for (int subIndex = 0; subIndex < sub.size(); subIndex++) {
                if (startIndex + subIndex >= main.size() ||
                    main[startIndex + subIndex] != sub[subIndex]) {
                    subFits = false;  // The substring doesn't match.
                    break;  // No need to continue further for this start index.
                }
            }

            if (subFits) {
                return true;  // Found a match, return true.
            }
        }

        return false;  // No match found.
    }
};