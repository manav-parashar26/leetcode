class Solution {
public:
    vector<int> parent, rank;
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
        if (rank[pu] < rank[pv])
            parent[pu] = pv;
        else if (rank[pu] > rank[pv])
            parent[pv] = pu;
        else {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n, 0);
        int cntex = 0;
        for (int i = 0; i < n; i++)
            parent[i] = i;
        for (auto edge : connections) {
            int u = edge[0];
            int v = edge[1];
            if (find(u) == find(v))
                cntex++;
            else
                unite(u, v);
        }
        int cntc = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                cntc++;
        }
        int ans = cntc - 1;
        if (cntex >= ans)
            return ans;
        return -1;
    }
};