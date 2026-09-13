class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        vector<pair<int, int>> ones1, ones2;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1)
                    ones1.push_back({i, j});

                if (img2[i][j] == 1)
                    ones2.push_back({i, j});
            }
        }

        map<pair<int, int>, int> freq;
        int ans = 0;


        for (auto p1 : ones1) {
            for (auto p2 : ones2) {
                int dr = p2.first - p1.first;
                int dc = p2.second - p1.second;

                freq[{dr, dc}]++;
                ans = max(ans, freq[{dr, dc}]);
            }
        }

        return ans;
    }
};