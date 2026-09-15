class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        vector<vector<pair<int, int>>> adj(n);

        for (auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        pq.push({0, 0});

        vector<long long> dist(n, LLONG_MAX);
        vector<int> ways(n, 0);

        dist[0] = 0;
        ways[0] = 1;

        int mod = 1e9 + 7;

        while (!pq.empty()) {

            auto [dis, node] = pq.top();
            pq.pop();
            if (dis > dist[node])
                continue;

            for (auto [adjnode, ewt] : adj[node]) {

                if (dis + ewt < dist[adjnode]) {

                    dist[adjnode] = dis + ewt;
                    ways[adjnode] = ways[node];

                    pq.push({dist[adjnode], adjnode});
                }

                else if (dis + ewt == dist[adjnode]) {

                    ways[adjnode] =
                        (ways[adjnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};