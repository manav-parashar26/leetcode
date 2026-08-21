class Solution {
    bool check(int node, int col, vector<vector<int>>& graph,
               vector<int>& color) {

        color[node] = col;

        for (int it : graph[node]) {

            if (color[it] == -1) {
                if (!check(it, !col, graph, color)) {
                    return false;
                }
            }
            else if (color[it] == col) {
                return false;
            }
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!check(i, 0, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};