class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Only consider odd numbers: index i -> number (2*i+1)
        int m = n / 2;
        vector<bool> isPrime(m, true);

        int limit = sqrt(n);
        for (int i = 1; (2*i+1) <= limit; i++) {
            if (isPrime[i]) {
                int p = 2*i + 1;
                for (int j = (p*p)/2; j < m; j += p) {
                    isPrime[j] = false;
                }
            }
        }

        // Count primes: +1 for "2"
        int cnt = 1;
        for (int i = 1; i < m; i++) {
            if (isPrime[i]) cnt++;
        }
        return cnt;
    }
};
