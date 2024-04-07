class Solution {
public:
    int maxScore(string st) {
        int n = st.size();
        vector<int> s(n);
        for(int i = 0; i < n; i++)
            s[i] = (i == 0) ? (st[i] == '1'? 1 : 0) : s[i-1] + (st[i] == '1'? 1 : 0);

            int max = 0;
            for(int i = 0; i < n - 1; i++)
            {
                int score = s[n-1] - s[i] + (i + 1 - s[i]);
                max = std::max(max, score);
            }
            return max;
    }

};