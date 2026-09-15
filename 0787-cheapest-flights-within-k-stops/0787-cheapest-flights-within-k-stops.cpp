class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it : flights)adj[it[0]].push_back({it[1],it[2]});
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        vector<int> dist(n,1e9);
        dist[src] = 0 ;
        while(!q.empty()){
            auto [stop,temp] = q.front();
            q.pop();
            auto [node,cost] = temp;
            if(stop > k)continue;
            for(auto i : adj[node]){
                auto [adjnode,wt] = i;
                if(cost + wt < dist[adjnode] && stop <= k){
                    dist[adjnode] = cost + wt;
                    q.push({stop+1,{adjnode,dist[adjnode]}});
                } 
            }
        }
        if(dist[dst] == 1e9)return -1;
        return dist[dst];
    }
};