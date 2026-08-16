class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        
        for (auto& p : prerequisites) {
            int a = p[0], b = p[1];
            adj[b].push_back(a);
            indeg[a]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indeg[i] == 0) q.push(i);
        }
        int visited = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            visited++;
            for (int next : adj[node]) {
                if (--indeg[next] == 0) {
                    q.push(next);
                }
            }
        }
        return visited == numCourses;
    }
};