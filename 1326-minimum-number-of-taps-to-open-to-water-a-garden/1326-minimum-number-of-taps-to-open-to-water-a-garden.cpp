class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<vector<int>> intervals;
        for(int i=0; i<ranges.size(); i++)
        {
            if(ranges[i]>0)
            intervals.push_back({i-ranges[i],i+ranges[i]});
        }
        sort(intervals.begin(),intervals.end());
        int count = 0;
        int end = 0;
        int maxreach = 0;
        for(int i=0; end<n; end = maxreach)
        {
            count++;
            while(i<intervals.size() && intervals[i][0]<=end)
            {
                maxreach = max(maxreach,intervals[i++][1]);
            }
            if(maxreach==end) return -1;
        }
        return count;
    }
};