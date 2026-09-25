class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (s[i] >= g[j])
                j++;
            i++;
        }
        return j;
    }
};