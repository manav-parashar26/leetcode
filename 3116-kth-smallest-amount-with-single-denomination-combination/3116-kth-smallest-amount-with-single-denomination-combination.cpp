class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
       long long low = 1;
        long long high = 1LL * (*std::min_element(coins.begin(), coins.end())) * k;
        int n = coins.size();

        auto count = [&](long long x) {
            long long ans = 0;

            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm = 1;
                int bits = 0;
                bool valid = true;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;
                        long long g = std::gcd(lcm, (long long)coins[i]);
                        long long term = lcm / g;

                        // Guard against multiplication overflow
                        if (term > x / coins[i]) {
                            valid = false;
                            break;
                        }
                        lcm = term * coins[i];
                    }
                }

                if (!valid) continue;

                long long multiples = x / lcm;
                if (bits % 2 == 1) {
                    ans += multiples;
                } else {
                    ans -= multiples;
                }
            }

            return ans;
        };

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (count(mid) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};