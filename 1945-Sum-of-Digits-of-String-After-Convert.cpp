class Solution {
public:
    int getLucky(string se, int k) {
        string s = "";
        for(int i = 0; i < se.size(); i++)
        {
            int x = se[i] - 'a' + 1;
            s += to_string(x);
        }

        long long ans = 0;
        while(k--)
        {
            long long sum = 0;
            for(int i = 0; i < s.size(); i++)
                sum += s[i] - '0';

            ans = sum;
            s = to_string(sum);
            if(sum < 10)
                break;
        }

        return ans;
    }
};