class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        //priority_queue Node is pair<start, <employeeIndex, intervalIndex>>
        //pair.second is used to get to next interval
        using PQ_Node = pair<int, pair<int, int>>;
        vector<Interval> ans;
        if (schedule.empty()) return ans;
        priority_queue<PQ_Node, vector<PQ_Node>, greater<>> pq;
        for(int i=0; i<schedule.size(); ++i) {
            if (schedule[i].size()) {
                pq.push({schedule[i][0].start, {i, 0}});
            }
        }
        //minimum value of end time of any employees schedule which started earliest
        int end = schedule[pq.top().second.first][0].start;
        while(pq.size()) {
            //find employee's schedule with minimum end time
            auto p = pq.top();
            pq.pop();
            int intervalIndex = p.second.second;
            int employeeIndex = p.second.first;
            if (p.first > end) {
                ans.push_back(Interval{end, p.first});
                end = schedule[employeeIndex][intervalIndex].end;
            } else {
                end = max(end, schedule[employeeIndex][intervalIndex].end);
            }
            ++intervalIndex;
            if (intervalIndex < schedule[employeeIndex].size()) {
            
                pq.push({schedule[employeeIndex][intervalIndex].start,
                         {employeeIndex, intervalIndex}});
            }
            
        }
        return ans;
    }
};