class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> s(nums.size());
        for(int i = 0; i < s.size(); i++)
            s[i] = (i == 0) ? nums[0] : nums[i] + s[i - 1];

        int ans = -1;
        if(s[s.size() - 1] - nums[0] == 0)
            return 0;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i - 1] == s[s.size() - 1] - s[i])
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};