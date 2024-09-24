class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        map<string, int> prefixMap;
        for (auto num : arr1) {
            string str1 = to_string(num);
            string prefix = "";
            for (auto ch : str1) {
                prefix += ch;
                prefixMap[prefix]++;
            }
        }

        int maxi = 0;
        for (auto num : arr2) {
            string str2 = to_string(num);
            string prefix = "";
            for (auto ch : str2) {
                prefix += ch;
                if (prefixMap[prefix] > 0) {
                    maxi = max(maxi, (int)prefix.size());
                }
            }
        }
        return maxi;
    }
};