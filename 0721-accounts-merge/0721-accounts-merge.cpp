class Solution {
public:
    vector<int>parent, size;
    int find(int x){
        if(parent[x] == x)return x;

        return parent[x]=find(parent[x]);
    }
    void unite(int u ,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv)return ;
        if(size[pu] < size[pv]){
            parent[pu] = pv;
            size[pv] += size[pu];
        }else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        size.resize(n,1);
        for(int i= 0 ; i < n ; i++)parent[i] = i;
        unordered_map<string,int>mpp;
        for(int i = 0 ; i< n ; i++){
            for(int j = 1 ; j < accounts[i].size() ; j++){
                string email = accounts[i][j];
                if(mpp.find(email) == mpp.end())mpp[email] = i;
                else unite(i,mpp[email]);
            }
        }
        vector<vector<string>> merged(n);
        for(auto it : mpp){
            string email = it.first;
            int account = it.second;
            int root = find(account);
            merged[root].push_back(email);
        }
        vector<vector<string>> ans;
        for(int i = 0 ; i < n ; i++){
            if(merged[i].empty())continue;
            sort(merged[i].begin(),merged[i].end());
            vector<string> temp ;
            temp.push_back(accounts[i][0]);
            for(auto email : merged[i])temp.push_back(email);
            ans.push_back(temp);
        }
        return ans;
    }
};