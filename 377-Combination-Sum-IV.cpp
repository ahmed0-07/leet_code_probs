class Solution {
public:
    vector<int> v;
    int dp[1005];

    int f(int a)
    {
        if(a == 0)
            return 1;

        if(dp[a] != -1)
            return dp[a];

        int c = 0;
        for(int i = 0; i < v.size(); i++)
        {
            if(v[i] > a)
                break;

            c += f(a - v[i]);
        }

        return dp[a] = c;
    }
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        v = nums;
        memset(dp, -1, sizeof(dp));
        return f(target);
    }
};