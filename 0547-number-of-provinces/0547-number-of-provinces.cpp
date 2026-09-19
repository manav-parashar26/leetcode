class Solution {
    // void dfs(int node, vector<vector<int>>& isConnected, vector<int>& vis) {
    //     vis[node] = 1;

    //     for (int j = 0; j < isConnected.size(); j++) {
    //         if (isConnected[node][j] == 1 && !vis[j]) {
    //             dfs(j, isConnected, vis);
    //         }
    //     }
    // }

public:
    vector<int> parent, rank;
    int find(int x){
        if(parent[x] ==  x)return x;

        return parent[x] = find(parent[x]);
    }
    void unite(int u ,int v, int &cnt){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)return;
        if(rank[pu] < rank[pv]){
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu]){
            parent[pv] = pu;
        }else{
            parent[pv] = pu;
            rank[pu]++;
        }
        cnt--;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        rank.resize(n,0);
        int cnt = n;
        for(int i = 0 ; i < n ; i++ )parent[i] = i;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(isConnected[i][j] == 1)unite(i,j,cnt);
            }
        }
        return cnt;
    }
};
        // vector<int> vis(n, 0);

        // int cnt = 0;

        // for (int i = 0; i < n; i++) {
        //     if (!vis[i]) {
        //         cnt++;
        //         dfs(i, isConnected, vis);
        //     }
        // }

        // return cnt;