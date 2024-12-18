class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        for (int i = 0; i < prices.size(); i++) {
            int x = i + 1;
            while (x < prices.size() && prices[x] > prices[i]) {
                x++;
            }
            if (x < prices.size())
                prices[i] -= prices[x];
        }
        return prices;
    }
};