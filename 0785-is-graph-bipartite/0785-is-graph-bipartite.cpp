class Solution {
    bool check(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;

        q.push(start);
        color[start] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {

                if (color[neighbor] == -1) {
                    color[neighbor] = !color[node];
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false;
                }
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
                if (!check(i, graph, color)) {
                    return false;
                }
            }
        }

        return true;
    }
};