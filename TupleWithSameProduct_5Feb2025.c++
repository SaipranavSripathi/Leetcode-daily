class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int numsLength = nums.size();

        vector<int> pairProducts;

        int totalNumberOfTuples = 0;

        // Iterate over nums to calculate all pairwise products
        for (int firstIndex = 0; firstIndex < numsLength; firstIndex++) {
            for (int secondIndex = firstIndex + 1; secondIndex < numsLength;
                 secondIndex++) {
                pairProducts.push_back(nums[firstIndex] * nums[secondIndex]);
            }
        }

        sort(pairProducts.begin(), pairProducts.end());

        int lastProductSeen = -1;
        int sameProductCount = 0;

        // Iterate over pairProducts to count how many times each product occurs
        for (int productIndex = 0; productIndex < pairProducts.size();
             productIndex++) {
            if (pairProducts[productIndex] == lastProductSeen) {
                // Increment the count of same products
                sameProductCount++;
            } else {
                // Calculate how many pairs had the previous product value
                int pairsOfEqualProduct =
                    (sameProductCount - 1) * sameProductCount / 2;

                totalNumberOfTuples += 8 * pairsOfEqualProduct;

                // Update lastProductSeen and reset sameProductCount
                lastProductSeen = pairProducts[productIndex];
                sameProductCount = 1;
            }
        }

        // Handle the last group of products (since the loop ends without adding
        // it)
        int pairsOfEqualProduct = (sameProductCount - 1) * sameProductCount / 2;
        totalNumberOfTuples += 8 * pairsOfEqualProduct;

        return totalNumberOfTuples;
    }
};