class Solution {
public:
    typedef pair<int,int> ppi;
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        int currtime = 0;
        priority_queue<ppi> pq;
        sort(courses.begin(),courses.end(),[&](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });
        int ans = 0;
        for(auto it:courses){
            if(currtime+it[0] <= it[1]){
                currtime += it[0];
                pq.push({it[0],it[1]});
                ans++;
            }
            else{
                if(pq.empty()) continue;
                int duration = pq.top().first;
                if(duration <= it[0]) continue;
                pq.pop();
                pq.push({it[0],it[1]});
                currtime += it[0] - duration;
            }
        }
        return ans;
    }
};