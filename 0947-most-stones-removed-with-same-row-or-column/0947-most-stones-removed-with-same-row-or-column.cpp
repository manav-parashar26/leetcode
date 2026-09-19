class Solution {
public:
    vector<int> parent, size;

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {

        int pu = find(u);
        int pv = find(v);

        if (pu == pv)
            return;

        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }

    int removeStones(vector<vector<int>>& stones) {

        int maxrow = 0;
        int maxcol = 0;

        for (auto it : stones) {
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }

        parent.resize(maxrow + maxcol + 2);
        size.resize(maxrow + maxcol + 2, 1);

        for (int i = 0; i < parent.size(); i++)
            parent[i] = i;

        unordered_map<int, int> mpp;

        for (auto it : stones) {

            int noderow = it[0];

            int nodecol = it[1] + maxrow + 1;

            unite(noderow, nodecol);

            mpp[noderow] = 1;
            mpp[nodecol] = 1;
        }

        int cnt = 0;

        for (auto it : mpp) {
            if (find(it.first) == it.first)
                cnt++;
        }

        return stones.size() - cnt;
    }
};