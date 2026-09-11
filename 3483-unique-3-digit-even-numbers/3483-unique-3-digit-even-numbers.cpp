class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);

        for (int x : digits)
            freq[x]++;

        int ans = 0;

        for (int a = 1; a <= 9; a++) {
            if (!freq[a]) continue;
            freq[a]--;

            for (int b = 0; b <= 9; b++) {
                if (!freq[b]) continue;
                freq[b]--;

                for (int c = 0; c <= 8; c += 2) {
                    if (freq[c])
                        ans++;
                }

                freq[b]++;
            }

            freq[a]++;
        }

        return ans;
    }
};