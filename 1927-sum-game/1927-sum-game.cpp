class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int lsum = 0, rsum = 0;
        int lq = 0, rq = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                lq++;
            else
                lsum += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                rq++;
            else
                rsum += num[i] - '0';
        }

        if ((lq + rq) % 2)
            return true;

        return (lsum - rsum) != (rq - lq) * 9 / 2;
    }
};