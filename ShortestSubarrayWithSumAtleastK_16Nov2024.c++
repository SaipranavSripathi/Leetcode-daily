const int MAX_SIZE = 1e5 + 1;
long long psum[MAX_SIZE];
int idx[MAX_SIZE];
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size(), res = n + 1, s{0}, e{0};
        long long sum{0};
        psum[e] = 0, idx[e++] = -1; // Initialize prefix sum and index
        for (int i{0}; i < n; ++i) {
            sum += nums[i];
            // Check if the current subarray sum is at least k
            while (s < e && sum - psum[s] >= k)
                res = std::min(res, i - idx[s++]);
            // Maintain monotonic increasing order in the deque
            while (s < e && sum <= psum[e - 1])
                e--;
            psum[e] = sum, idx[e++] = i;
        }
        return res > n ? -1 : res;
    }
};