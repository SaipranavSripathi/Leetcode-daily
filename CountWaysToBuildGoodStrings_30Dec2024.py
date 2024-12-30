class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        MOD = 10**9 + 7

        # dp[i] will store the number of good strings of length i
        dp = [0] * (high + 1)

        # Base case: There's 1 way to make an empty string
        dp[0] = 1

        # Iterate over all lengths from 1 to high
        for length in range(1, high + 1):
            # If we append '0' zero times, we reduce the length by `zero`
            if length >= zero:
                dp[length] = (dp[length] + dp[length - zero]) % MOD

            # If we append '1' one times, we reduce the length by `one`
            if length >= one:
                dp[length] = (dp[length] + dp[length - one]) % MOD

        # Sum up all dp[i] for lengths in the range [low, high]
        return sum(dp[low:high + 1]) % MOD