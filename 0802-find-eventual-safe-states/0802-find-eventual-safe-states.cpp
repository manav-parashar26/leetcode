class Solution {
public:
    vector<int> state;

    bool dfs(int node, vector<vector<int>>& graph) {

        if (state[node] == 1)
            return false;

        if (state[node] == 2)
            return true;

        state[node] = 1;

        for (int next : graph[node]) {

            if (!dfs(next, graph))
                return false;
        }

        state[node] = 2;

        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

        int n = graph.size();

        state.resize(n, 0);

        vector<int> ans;

        for (int i = 0; i < n; i++) {

            if (dfs(i, graph))
                ans.push_back(i);
        }

        return ans;
    }
};