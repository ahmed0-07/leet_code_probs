class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long sum = 0;
        for(int i = 0; i < chalk.size(); i++)
            sum += chalk[i];

        k = k % sum;

        int idx = -1;
        for(int i = 0; i < chalk.size(); i++)
        {
            if(chalk[i] <= k)
                k -= chalk[i];
            else
            {
                idx = i;
                break;
            }
        }

        return idx;
    }
};