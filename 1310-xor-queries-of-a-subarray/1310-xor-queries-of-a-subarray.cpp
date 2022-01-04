class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;
        vector<int> prefix(n);
        for(int i=0; i<n; i++)
        {
            if(i==0)
                prefix[0] = arr[i];
            else
                prefix[i] = arr[i]^prefix[i-1];
        }
        for(auto it:queries)
        {
            int left = it[0];
            int right = it[1];
            if(left>0)
                ans.push_back(prefix[left-1]^prefix[right]);
            else
                ans.push_back(prefix[right]);
        }
        return ans;
    }
};