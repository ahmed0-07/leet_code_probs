class Solution {
public:
    int dp[2500 + 1][2500 + 1];
    int sz;
    int LIS(int idx, int last_idx, vector<int>& nums)
    {
        if(idx == sz)
            return 0;

        if(dp[idx][last_idx] != -1)
            return dp[idx][last_idx];

        int ch1 = LIS(idx + 1, last_idx, nums);
        int ch2 = 0;
        if(last_idx == nums.size())
            ch2 = 1 + LIS(idx + 1, idx, nums);
        else if(nums[idx] > nums[last_idx])
            ch2 = 1 + LIS(idx + 1, idx, nums);

        return dp[idx][last_idx] = max(ch1, ch2);
    }
    int lengthOfLIS(vector<int>& nums) {
        sz = nums.size();
        memset(dp, -1, sizeof(dp));
        return LIS(0, sz, nums);
    }
};