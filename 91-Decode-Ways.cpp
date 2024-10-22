class Solution {
public:
    int dp[105];
    string s;
    int f(int idx)
    {
        if(idx == s.size())
            return 1;
        
        if(s[idx] == '0')
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int ch1 = 0, ch2 = 0;
        ch1 = f(idx+1);
        
        string x = \\;
        x +=s[idx];
        x +=s[idx+1];
        if(idx+1 < s.size() && x >= \1\ && x <= \26\)
            ch2 += f(idx+2);

        return dp[idx] = ch1 + ch2;
    }
    int numDecodings(string t) {
        s = t;
        memset(dp, -1, sizeof(dp));
        return f(0);
    }
};