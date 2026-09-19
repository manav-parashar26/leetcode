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
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        parent.resize(n * n);
        size.resize(n * n, 1);

        for (int i = 0; i < n * n; i++)
            parent[i] = i;

        vector<pair<int, int>> cells;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                cells.push_back({grid[r][c], r * n + c});
            }
        }

        sort(cells.begin(), cells.end());

        vector<bool> active(n * n, false);

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (auto [height, node] : cells) {

            int r = node / n;
            int c = node % n;

            active[node] = true;

            for (int k = 0; k < 4; k++) {

                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr < 0 || nr >= n || nc < 0 || nc >= n)
                    continue;

                int neighbour = nr * n + nc;

                if (active[neighbour]) {
                    unite(node, neighbour);
                }
            }

            int start = 0;
            int end = n * n - 1;

            if (find(start) == find(end))
                return height;
        }

        return -1;
    }
};