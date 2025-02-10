class Solution {
    public:
        string clearDigits(string s) {
            // This variable keeps track of the actual length of the resulting
            // string
            int answerLength = 0;
    
            // Iterate through each character in the input string
            for (int charIndex = 0; charIndex < s.size(); charIndex++) {
                // If the current character is a digit
                if (isdigit(s[charIndex])) {
                    // Decrement answerLength to remove the last character from the
                    // result
                    answerLength = max(answerLength - 1, 0);
                } else {
                    // Place the character in the "answer" portion of the string
                    s[answerLength++] = s[charIndex];
                }
            }
    
            // Resize the string to match the actual length of the answer
            s.resize(answerLength);
    
            return s;
        }
    };