class Solution {
public:
    vector<int> v;
    int dp[200+1][10001];
    bool fun(int idx, int sum)
    {
        if(sum < 0)
            return false;

        if(sum == 0)
            return true;

        if(idx == v.size())
            return false;

        if(dp[idx][sum] != -1)
            return dp[idx][sum];

        return dp[idx][sum] = (fun(idx+1, sum) || fun(idx+1, sum - v[idx]));
    }
    bool canPartition(vector<int>& nums) {
        v = nums;
        int sum = 0;
        for(int i = 0; i < nums.size(); i++)
            sum += nums[i];

        if(sum % 2)
            return false;
        memset(dp, -1, sizeof(dp));
        return fun(0, sum / 2);
    }
};