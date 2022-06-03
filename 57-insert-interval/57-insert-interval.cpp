class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int n = intervals.size();
        int i=0;
        for(i; i<n; i++)
        {
            auto it = intervals[i];
            if(newInterval[1] < it[0])
            {
                ans.push_back(newInterval);
                break;
            }
            else if(newInterval[0] > it[1])
            {
                ans.push_back(it);
            }
            else
            {
                newInterval[0] = min(newInterval[0],it[0]);
                newInterval[1] = max(newInterval[1],it[1]);
            }
        }
        while(i<n)
        {
            ans.push_back(intervals[i++]);
        }
        if(ans.empty() or newInterval[0]>ans.back()[1])
            ans.push_back(newInterval);
        return ans;
    }
};