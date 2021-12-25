class Solution {
public:
        static bool cmp(vector<int> v1, vector<int> v2)
        {
            if(v1[0]==v2[0])
                return v1[1]<v2[1];
            else return v1[0]<v2[0];
        }
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(intervals.begin(),intervals.end(),cmp);
        pq.push(intervals[0][1]);
        ans = 1;
        int n = intervals.size();
        for(int i=1; i<n; i++)
        {
            if(intervals[i][0]<pq.top())
                pq.push(intervals[i][1]);
            else
            {
                pq.pop();
                pq.push(intervals[i][1]);
            }
            ans = max(ans,(int)pq.size());
        }
        return ans;
    }
};