class Solution {
public:
    struct Node {
        int prod;
        int pref[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                pref[i] = 0;
        }
    };

    int k;

    Node mergeNode(const Node &a, const Node &b) {
        Node res;

        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left segment
        for (int r = 0; r < k; r++) {
            res.pref[r] += a.pref[r];
        }

        // Prefixes which contain the whole left segment
        // and some prefix of the right segment
        for (int r = 0; r < k; r++) {
            int rem = (a.prod * r) % k;
            res.pref[rem] += b.pref[r];
        }

        return res;
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries
    ) {
        this->k = k;

        int n = nums.size();

        // Iterative segment tree
        vector<Node> seg(2 * n);

        // Build leaves
        for (int i = 0; i < n; i++) {
            int rem = nums[i] % k;

            seg[n + i].prod = rem;
            seg[n + i].pref[rem] = 1;
        }

        // Build tree
        for (int i = n - 1; i >= 1; i--) {
            seg[i] = mergeNode(seg[2 * i], seg[2 * i + 1]);
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // -------------------------
            // Point update
            // -------------------------

            int pos = n + index;

            // Reset leaf
            seg[pos] = Node();

            int rem = value % k;

            seg[pos].prod = rem;
            seg[pos].pref[rem] = 1;

            // Update ancestors
            for (pos /= 2; pos >= 1; pos /= 2) {
                seg[pos] = mergeNode(seg[2 * pos], seg[2 * pos + 1]);
            }

            // -------------------------
            // Range query [start, n-1]
            // -------------------------

            int l = n + start;
            int r = n + n - 1;

            Node leftResult;
            Node rightResult;

            while (l <= r) {

                if (l & 1) {
                    leftResult = mergeNode(leftResult, seg[l]);
                    l++;
                }

                if (!(r & 1)) {
                    rightResult = mergeNode(seg[r], rightResult);
                    r--;
                }

                l /= 2;
                r /= 2;
            }

            Node result = mergeNode(leftResult, rightResult);

            ans.push_back(result.pref[x]);
        }

        return ans;
    }
};