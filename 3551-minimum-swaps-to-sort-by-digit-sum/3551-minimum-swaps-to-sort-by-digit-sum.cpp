class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<array<int, 3>> a(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i], s = 0;
            while (x > 0) {
                s += x % 10;
                x /= 10;
            }
            a[i] = {s, nums[i], i};
        }

        sort(a.begin(), a.end());

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || a[i][2] == i)
                continue;

            int j = i, cnt = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = a[j][2];
                cnt++;
            }

            ans += cnt - 1;
        }

        return ans;
    }
};