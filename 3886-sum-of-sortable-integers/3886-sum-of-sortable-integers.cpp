class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            int last = -1;

            for (int i = 0; i < n && ok; i += k) {
                int drops = 0, pos = -1;

                for (int j = i; j < i + k; j++) {
                    int nxt = (j == i + k - 1) ? i : j + 1;
                    if (nums[j] > nums[nxt]) {
                        drops++;
                        pos = nxt;
                    }
                }

                if (drops > 1) {
                    ok = false;
                    break;
                }

                int first = (pos == -1) ? nums[i] : nums[pos];

                if (last != -1 && last > first) {
                    ok = false;
                    break;
                }

                last = (pos == -1) ? nums[i + k - 1] : nums[pos - 1 < i ? i + k - 1 : pos - 1];
            }

            if (ok) ans += k;
        }

        return (int)ans;
    }
};