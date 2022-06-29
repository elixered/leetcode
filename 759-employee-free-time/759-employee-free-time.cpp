/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        map<int,int> mp;
        for(auto employee:schedule){
            for(auto interval:employee){
                mp[interval.start]++;
                mp[interval.end]--;
            }
        }
        int start = -1;
        int prev = 0;
        vector<Interval> ans;
        for(auto it:mp){
            int curr = prev + it.second;
            if(curr == 0){
                if(prev!=0)
                    start = it.first;
            }
            else{
                if(prev == 0 && start != -1){
                    ans.push_back(Interval(start,it.first));
                }
            }
            prev = curr;
        }
        return ans;
    }
};