class Solution {
    public:
        vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
            long long sum = 0, sqrSum = 0;
            long long n = grid.size();
            long long total = n * n;
    
            // Calculate actual sum and squared sum from grid
            for (int row = 0; row < n; ++row) {
                for (int col = 0; col < n; ++col) {
                    sum += grid[row][col];
                    sqrSum +=
                        static_cast<long long>(grid[row][col]) * grid[row][col];
                }
            }
    
            // Calculate differences from expected sums
            // Expected sum: n(n+1)/2, Expected square sum: n(n+1)(2n+1)/6
            long long sumDiff = sum - total * (total + 1) / 2;
            long long sqrDiff = sqrSum - total * (total + 1) * (2 * total + 1) / 6;
    
            // Using math: If x is repeated and y is missing
            // sumDiff = x - y
            // sqrDiff = x² - y²
            int repeat = (sqrDiff / sumDiff + sumDiff) / 2;
            int missing = (sqrDiff / sumDiff - sumDiff) / 2;
    
            return {repeat, missing};
        }
    };