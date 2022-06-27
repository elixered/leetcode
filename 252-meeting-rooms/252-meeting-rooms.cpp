class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<int> line(1000002,0);
        for(auto it:intervals)
        {
            line[it[0]]++;
            line[it[1]]--;
        }
        int s = 0;
        for(auto it:line){
            s += it;
            if(s>1) return false;
        }
        return true;
    }
};