class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        priority_queue<pair<pair<int, int>, int>,vector<pair<pair<int, int>, int>>,greater<pair<pair<int, int>, int>>> pq;
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        pq.push({{0, 0}, 0});
        dist[0][0] = 0; 

        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};

        while (!pq.empty()) {
            auto [cell, diff] = pq.top();
            pq.pop();

            auto [r, c] = cell;
            if (r == n - 1 && c == m - 1)
                return diff;

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < n && nc >= 0 && nc < m ) {
                    int neweffort = max(abs(heights[r][c] - heights[nr][nc]),diff);
                    if(neweffort < dist[nr][nc]){
                        dist[nr][nc] = neweffort;
                        pq.push({{nr, nc}, dist[nr][nc]});
                    }
                }
            }
        }

        return 0;
    }
};