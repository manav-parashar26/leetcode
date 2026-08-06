class Solution {
public:
    bool check(int x, int t) {
        long long prod = 1;

        while (x) {
            int d = x % 10;
            if (d == 0) return true;   // product = 0
            prod *= d;
            x /= 10;
        }

        return prod % t == 0;
    }

    int smallestNumber(int n, int t) {
        while (!check(n, t))
            n++;
        return n;
    }
};