class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr;
        for(int i=0; i<n; i++)
            arr.push_back({nums[i],i});
        sort(arr.begin(),arr.end());
        int mini = n;
        int maxi = -1;
        for(int i=0; i<n; i++)
        {
            if(i!=arr[i].second)
            {
                mini = min(mini,arr[i].second);
                maxi = max(maxi,arr[i].second);
            }
        }
        if(mini==n or maxi==-2) return 0;
        else return maxi-mini+1;
    }
};