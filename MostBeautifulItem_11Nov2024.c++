class Solution {
public:
    static vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end()); // Sort items by price
        const int n = items.size(), m = queries.size();

        vector<int> mostBeauty(n);
        mostBeauty[0] = items[0][1];

        // Build up the mostBeauty array
        for (int i = 1; i < n; i++)
            mostBeauty[i] = max(mostBeauty[i-1], items[i][1]);

        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int query = queries[i];
            vector<int>&& target={query, INT_MAX};
            // Use upper_bound to find the first item with a price > query
            int j = upper_bound(items.begin(), items.end(), target)-items.begin();
            // If j is 0, no items have price <= query
            if (j == 0) ans[i] = 0;
            else ans[i] = mostBeauty[j - 1];
        }

        return ans;
    }
};