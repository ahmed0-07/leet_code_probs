class Solution {
public:
    int findRadius(vector<int>& h, vector<int>& heaters) {
        sort(h.begin(), h.end());
        sort(heaters.begin(), heaters.end());
        int start = 0, end = 1e9, ans = -1;
        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            if(possible(h, heaters, mid))
                end = mid - 1, ans = mid;
            else
                start = mid + 1;
        }
        return ans;
    }

    bool possible(vector<int>& h, vector<int>& heaters, int rad)
    {
        int j = 0; // counter of coverd houses and track for indices
        for(int i = 0; i < heaters.size(); i++)
        {
            int l = heaters[i] - rad, r = heaters[i] + rad;

            while(j < h.size() && h[j] >= l && h[j] <= r) // if the house in the range counter++
                j++; 
        }
        return j == h.size();
    }
};