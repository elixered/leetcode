class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b)
    {
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return true;
        sort(intervals.begin(),intervals.end(),cmp);
        int end = intervals[0][1];
        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0]>=end)
                end = intervals[i][1];
            else return false;
        }
        return true;
    }
};