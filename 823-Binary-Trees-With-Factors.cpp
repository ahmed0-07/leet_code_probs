class Solution {
public:
    unordered_map<long long, int> dp;
    unordered_set<long long> nums;
    int idx;
    long long cnt_root(long long x)
    {
        if(dp.count(x))
            return dp[x];

        long long c = 1;
        for(auto i : nums)
        {
            if(x % i == 0 && nums.count(x / i))
            {
                long long ans = (cnt_root(i) * cnt_root(x / i)) % 1000000007;
                c = (c + ans) % 1000000007;
            }
        }

        return dp[x] = c;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        nums.insert(arr.begin(), arr.end());
        int c = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            c = (c + cnt_root(arr[i])) % 1000000007;
        }

        return c;
    }
};