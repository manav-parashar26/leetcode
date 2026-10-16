class Solution {
    static constexpr int MOD = 1e9 + 7;

    struct SegmentTree {
        int n;
        vector<long long> sum;
        vector<long long> sum_sq;
        vector<long long> lazy;

        SegmentTree(int n) : n(n) {
            sum.assign(4 * n, 0);
            sum_sq.assign(4 * n, 0);
            lazy.assign(4 * n, 0);
        }

        void apply(int node, int l, int r, long long val) {
            val %= MOD;
            long long len = (r - l + 1);
            
            // sum_sq' = sum_sq + 2 * val * sum + val^2 * len
            sum_sq[node] = (sum_sq[node] + 2 * val % MOD * sum[node] % MOD + val * val % MOD * len % MOD) % MOD;
            // sum' = sum + val * len
            sum[node] = (sum[node] + val * len % MOD) % MOD;
            // accumulate lazy
            lazy[node] = (lazy[node] + val) % MOD;
        }

        void push(int node, int l, int r) {
            if (lazy[node] != 0) {
                int mid = l + (r - l) / 2;
                apply(2 * node, l, mid, lazy[node]);
                apply(2 * node + 1, mid + 1, r, lazy[node]);
                lazy[node] = 0;
            }
        }

        void pull(int node) {
            sum[node] = (sum[2 * node] + sum[2 * node + 1]) % MOD;
            sum_sq[node] = (sum_sq[2 * node] + sum_sq[2 * node + 1]) % MOD;
        }

        void update(int node, int l, int r, int ql, int qr, long long val) {
            if (ql <= l && r <= qr) {
                apply(node, l, r, val);
                return;
            }
            push(node, l, r);
            int mid = l + (r - l) / 2;
            if (ql <= mid) {
                update(2 * node, l, mid, ql, qr, val);
            }
            if (qr > mid) {
                update(2 * node + 1, mid + 1, r, ql, qr, val);
            }
            pull(node);
        }
    };

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        SegmentTree tree(n);
        unordered_map<int, int> last_pos;
        
        long long total_ans = 0;

        for (int i = 0; i < n; ++i) {
            int prev = last_pos.count(nums[i]) ? last_pos[nums[i]] : -1;
            int L = prev + 1;
            int R = i;

            // Range add 1 to starting indices in [L, R]
            tree.update(1, 0, n - 1, L, R, 1);
            last_pos[nums[i]] = i;

            // The root of the segment tree maintains the sum of squares across all active subarrays
            total_ans = (total_ans + tree.sum_sq[1]) % MOD;
        }

        return (total_ans % MOD + MOD) % MOD;
    }
};