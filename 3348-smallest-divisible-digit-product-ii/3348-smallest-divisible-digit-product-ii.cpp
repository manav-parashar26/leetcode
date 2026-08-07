class Solution {
public:
    static constexpr int INF = 1e9;

    int factor[10][4];

    int A, B, C, D;
    vector<int> dp;

    int id(int a, int b, int c, int d) {
        return (((a * (B + 1) + b) * (C + 1) + c)
                * (D + 1) + d);
    }

    void init() {
        memset(factor, 0, sizeof(factor));

        factor[2][0] = 1;
        factor[3][1] = 1;
        factor[4][0] = 2;
        factor[5][2] = 1;
        factor[6][0] = 1;
        factor[6][1] = 1;
        factor[7][3] = 1;
        factor[8][0] = 3;
        factor[9][1] = 2;
    }

    int solve(int a, int b, int c, int d) {

        if (a == 0 && b == 0 && c == 0 && d == 0)
            return 0;

        int idx = id(a, b, c, d);

        if (dp[idx] != -1)
            return dp[idx];

        int ans = INF;

        for (int digit = 2; digit <= 9; digit++) {

            int na = max(0, a - factor[digit][0]);
            int nb = max(0, b - factor[digit][1]);
            int nc = max(0, c - factor[digit][2]);
            int nd = max(0, d - factor[digit][3]);

            // This digit does not satisfy any
            // currently required factor.
            if (na == a && nb == b &&
                nc == c && nd == d)
                continue;

            int nxt = solve(na, nb, nc, nd);

            if (nxt != INF)
                ans = min(ans, nxt + 1);
        }

        return dp[idx] = ans;
    }

    int minDigits(const array<int, 4>& need) {
        return solve(
            need[0],
            need[1],
            need[2],
            need[3]
        );
    }

    string build(int len, array<int, 4> need) {

        string ans;
        ans.reserve(len);

        for (int pos = 0; pos < len; pos++) {

            int left = len - pos - 1;

            for (int digit = 1; digit <= 9; digit++) {

                array<int, 4> rem;

                for (int j = 0; j < 4; j++) {
                    rem[j] =
                        max(0, need[j] - factor[digit][j]);
                }

                if (minDigits(rem) <= left) {

                    ans.push_back(char('0' + digit));
                    need = rem;

                    break;
                }
            }
        }

        return ans;
    }

    string smallestNumber(string num, long long t) {

        init();

        // Factorize t
        array<int, 4> need = {0, 0, 0, 0};

        int primes[4] = {2, 3, 5, 7};

        for (int i = 0; i < 4; i++) {
            while (t % primes[i] == 0) {
                need[i]++;
                t /= primes[i];
            }
        }

        // t contains a prime other than 2,3,5,7
        if (t != 1)
            return "-1";

        A = need[0];
        B = need[1];
        C = need[2];
        D = need[3];

        int totalStates =
            (A + 1) *
            (B + 1) *
            (C + 1) *
            (D + 1);

        dp.assign(totalStates, -1);

        int n = num.size();

        // Prefix factor counts and zero counts
        vector<array<int, 4>> pref(n + 1);
        vector<int> zeros(n + 1, 0);

        for (int i = 0; i < n; i++) {

            pref[i + 1] = pref[i];
            zeros[i + 1] = zeros[i];

            int digit = num[i] - '0';

            if (digit == 0) {
                zeros[i + 1]++;
                continue;
            }

            for (int j = 0; j < 4; j++) {
                pref[i + 1][j] += factor[digit][j];
                pref[i + 1][j] =
                    min(pref[i + 1][j], need[j]);
            }
        }

        // Check num itself
        if (zeros[n] == 0) {

            bool ok = true;

            for (int j = 0; j < 4; j++) {
                if (pref[n][j] < need[j]) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                return num;
        }

        // Try same-length answer.
        // Change the rightmost possible position.
        for (int i = n - 1; i >= 0; i--) {

            // Prefix must contain no zero.
            if (zeros[i] > 0)
                continue;

            int cur = num[i] - '0';

            for (int digit = cur + 1; digit <= 9; digit++) {

                array<int, 4> rem;

                for (int j = 0; j < 4; j++) {

                    int have =
                        pref[i][j] + factor[digit][j];

                    rem[j] =
                        max(0, need[j] - have);
                }

                int suffixLen = n - i - 1;

                if (minDigits(rem) <= suffixLen) {

                    string ans = num.substr(0, i);

                    ans.push_back(char('0' + digit));

                    ans += build(suffixLen, rem);

                    return ans;
                }
            }
        }

        // Need a longer number.
        int L = max(n + 1, minDigits(need));

        return build(L, need);
    }
};