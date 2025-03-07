class Solution {
    public:
        vector<int> closestPrimes(int left, int right) {
            vector<int> primeNumbers;
    
            // Find all prime numbers in the given range
            for (int candidate = left; candidate <= right; candidate++) {
                if (candidate % 2 == 0 and candidate > 2) continue;
                if (isPrime(candidate)) {
                    // If a twin prime (or [2, 3]) is found, return immediately
                    if (!primeNumbers.empty() &&
                        candidate <= primeNumbers.back() + 2) {
                        return {primeNumbers.back(), candidate};
                    }
                    primeNumbers.push_back(candidate);
                }
            }
    
            // If fewer than 2 primes exist, return {-1, -1}
            if (primeNumbers.size() < 2) return {-1, -1};
    
            // Find the closest prime pair
            vector<int> closestPair = {-1, -1};
            int minDifference = 1e6;
    
            for (int index = 1; index < primeNumbers.size(); index++) {
                int difference = primeNumbers[index] - primeNumbers[index - 1];
                if (difference < minDifference) {
                    minDifference = difference;
                    closestPair = {primeNumbers[index - 1], primeNumbers[index]};
                }
            }
    
            return closestPair;
        }
    
    private:
        // Function to check if a number is prime
        bool isPrime(int number) {
            if (number == 1) return false;
            for (int divisor = 2; divisor <= sqrt(number); divisor++) {
                if (number % divisor == 0) return false;
            }
            return true;
        }
    };