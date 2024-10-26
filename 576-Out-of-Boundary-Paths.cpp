class Solution {
public:
    int dp[55][55][55];
    int m, n;
    int f(int i, int j, int mx)
    {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;

        if(!mx)
            return 0;

        if(dp[i][j][mx] != -1)
            return dp[i][j][mx];
        int c = 0;
        c = (c + f(i, j + 1, mx - 1)) % 1000000007;
        c = (c + f(i, j - 1, mx - 1)) % 1000000007;
        c = (c + f(i + 1, j, mx - 1)) % 1000000007;
        c = (c + f(i - 1, j, mx - 1)) % 1000000007;

        return dp[i][j][mx] = c % 1000000007;
    }
    int findPaths(int mm, int nn, int maxMove, int startRow, int startColumn) {
        if(!maxMove)
            return 0;
        memset(dp, -1, sizeof(dp));
        n = nn, m = mm;
        return f(startRow, startColumn, maxMove);
    }
};