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

    int largestIsland(vector<vector<int>>& grid) {

        int n = grid.size();

        parent.resize(n * n);
        size.resize(n * n, 1);

        for (int i = 0; i < n * n; i++)
            parent[i] = i;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        // --------------------------------
        // Step 1: Build all existing islands
        // --------------------------------

        for (int r = 0; r < n; r++) {

            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 0)
                    continue;

                int node = r * n + c;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= n)
                        continue;

                    if (grid[nr][nc] == 0)
                        continue;

                    int neighbour = nr * n + nc;

                    unite(node, neighbour);
                }
            }
        }

        // --------------------------------
        // Step 2: Try converting every 0
        // --------------------------------

        int ans = 0;

        for (int r = 0; r < n; r++) {

            for (int c = 0; c < n; c++) {

                if (grid[r][c] == 1) {

                    // In case grid contains all 1s
                    ans = max(ans, size[find(r * n + c)]);
                    continue;
                }

                int newSize = 1;

                // Store unique neighbouring components
                set<int> components;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    if (nr < 0 || nr >= n ||
                        nc < 0 || nc >= n)
                        continue;

                    if (grid[nr][nc] == 0)
                        continue;

                    int neighbour = nr * n + nc;

                    components.insert(find(neighbour));
                }

                // Add sizes of all different islands
                for (int root : components) {
                    newSize += size[root];
                }

                ans = max(ans, newSize);
            }
        }

        return ans;
    }
};