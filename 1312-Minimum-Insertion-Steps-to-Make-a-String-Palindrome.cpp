class Solution {
public:
    int dp[505][505];
    string t;
    int f(int i, int j)
    {
        if(i >= j)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(t[i] == t[j])
            return dp[i][j] = f(i+1, j-1);

        int ch1 = 1 + f(i, j - 1);
        int ch2 = 1 + f(i + 1, j);
        return dp[i][j] = min(ch1, ch2);
    }
    int minInsertions(string s) {
        t = s;
        memset(dp, -1, sizeof(dp));
        return f(0, s.size() - 1);
    }
};