class Solution {
public:
    struct Node {
        int pref, suff, best, len;
        char lc, rc;
    }; 

    static Node merge(const Node& L, const Node& R) {
        if (L.len == 0)
            return R; 
        if (R.len == 0)
            return L;
        Node res;
        res.len = L.len + R.len;
        res.lc = L.lc;
        res.rc = R.rc;
        res.pref = L.pref;
        if (L.pref == L.len && L.rc == R.lc)
            res.pref = L.len + R.pref;
        res.suff = R.suff;
        if (R.suff == R.len && L.rc == R.lc)
            res.suff = R.len + L.suff;
        res.best = max(L.best, R.best);
        if (L.rc == R.lc)
            res.best = max(res.best, L.suff + R.pref);
        return res;
    }

    vector<Node> tree;
    int sz;

    vector<int> longestRepeating(string s, string qc, vector<int>& qi) {
        int n = s.size();
        sz = 1;
        while (sz < n)
            sz <<= 1; 
        tree.assign(2 * sz,
                    Node{0, 0, 0, 0, 0, 0}); 
        for (int i = 0; i < n; i++)
            tree[sz + i] = {1, 1, 1, 1, s[i], s[i]};
        for (int i = sz - 1; i >= 1; i--)
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);

        vector<int> ans;
        ans.reserve(qi.size());
        for (size_t i = 0; i < qi.size(); i++) {
            int idx = qi[i] + sz;
            tree[idx] = {1, 1, 1, 1, qc[i], qc[i]};
            for (idx >>= 1; idx >= 1; idx >>= 1)
                tree[idx] = merge(tree[2 * idx], tree[2 * idx + 1]);
            ans.push_back(tree[1].best);
        }
        return ans;
    }
};