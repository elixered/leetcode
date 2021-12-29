class TopVotedCandidate {
public:
    unordered_map<int,int> count;
    vector<int> ans;
    vector<int> time;
    TopVotedCandidate(vector<int>& person, vector<int>& times) {
        time = times;
        int n = times.size();
        int winner = 0;
        for(int i=0; i<n; i++)
        {
            count[person[i]]++;
            if(count[person[i]]>=count[winner])
            {
                winner = person[i];
            }
            ans.push_back(winner);
        }
    }
    
    int q(int t) {
        auto itr = lower_bound(time.begin(),time.end(),t);
        if(itr==time.end())
            return ans.back();
        if(*itr!=t)
        {
            if(itr==time.begin())
                return 0;
            else itr--;
        }
            int idx = itr-time.begin();
            return ans[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */