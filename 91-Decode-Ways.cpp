class Solution {
public:
    int dp[105];
    string s;
    int f(int idx, string ans)
    {
        if(ans.size() == s.size())
            return 1;
        else if(idx >= s.size())
            return 0;

        if(dp[idx] != -1)
            return dp[idx];

        int ch1 = 0, ch2 = 0;
        if(s[idx] != '0')
        {
            ans += s[idx];
            ch1 += f(idx+1, ans);
        }
        
        string x = \\;
        x +=s[idx];
        x +=s[idx+1];
        if(s[idx] != '0' && idx+1 < s.size() && x <= \26\)
        {
            ans += s[idx+2];
            ch2 += f(idx+2, ans);
        }

        return dp[idx] = ch1 + ch2;
    }
    int numDecodings(string t) {
        s = t;
        memset(dp, -1, sizeof(dp));
        return f(0, \\);
    }
};