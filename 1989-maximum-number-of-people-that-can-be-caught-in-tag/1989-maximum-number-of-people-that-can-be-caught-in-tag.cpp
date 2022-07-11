class Solution {
public:
    int catchMaximumAmountofPeople(vector<int>& team, int dist) {
        deque<int> t0,t1;
        int ans = 0;
        for(int i=0; i<team.size(); ++i){
            while(!t0.empty() && t0.front()+dist<i)
                t0.pop_front();
            while(!t1.empty() && t1.front()+dist<i)
                t1.pop_front();
            if(team[i] == 1){
                if(!t0.empty()){
                    ans++;
                    t0.pop_front();
                }
                else t1.push_back(i);
            }
            else{
                if(!t1.empty()){
                    ans++;
                    t1.pop_front();
                }
                else t0.push_back(i);
            }
        }
        return ans;
    }
};