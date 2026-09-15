class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        pq.push({0, k});

        vector<int> vis(n + 1, 0);

        int t = 0;
        int count = 0;

        while (!pq.empty()) {

            auto [wt, n1] = pq.top();
            pq.pop();

            if (vis[n1])
                continue;

            vis[n1] = 1;
            count++;

            t = max(t, wt);

            for (auto [n2, ewt] : adj[n1]) {

                if (!vis[n2]) {
                    pq.push({wt + ewt, n2});
                }
            }
        }

        if (count != n)
            return -1;

        return t;
    }
};