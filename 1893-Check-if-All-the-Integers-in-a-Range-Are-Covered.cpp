class Solution {
public:
    bool isCovered(vector<vector<int>>& ra, int l, int r) {
        int ans = 0;
        for(int i = l; i <= r; i++)
        {
            for(int j = 0; j < ra.size(); j++)
            {
                if(i >= ra[j][0] && i <= ra[j][1])
                {
                    ans = 1;
                    break;
                }
                else
                    ans = 0;
            }

            if(ans)
                continue;
            else
                return false;
        }
        return true;
    }
};