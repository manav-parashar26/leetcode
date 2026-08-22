class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;
        int ld = 0;
        int sum = 0;
        long long pro = 1;

        while (n > 0) {
            ld = n % 10;
            sum += ld;
            pro *= ld;

            n = n / 10;
        }

        return original % (sum + pro) == 0;
    }
};