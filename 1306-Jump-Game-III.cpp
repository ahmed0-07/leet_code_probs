class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int min = INT_MAX;
        for(int i = 1; i < arr.size(); i++)
            if(abs(arr[i] - arr[i-1]) < min)
                min = abs(arr[i] - arr[i-1]);

        for(int i = 1; i < arr.size(); i++)
            if(abs(arr[i] - arr[i-1]) == min)
                res.push_back({arr[i-1], arr[i]});

        return res;
    }
};