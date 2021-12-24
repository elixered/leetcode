class Solution {
public:
    typedef pair<int,int> ppi;
    struct cmp{
        bool operator()(ppi p1, ppi p2)
        {
            if(p1.first==p2.first)
                return p1.second < p2.second;
            else return p1.first<p2.first;
        }
    };
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> ans;
        priority_queue<ppi,vector<ppi>,cmp> pq;
        int idx = 0;
        for(auto row:mat)
        {
            int count = 0;
            for(auto c:row)
            {
                if(c==1) count++;
                else break;
            }
            pq.push({count,idx});
            idx++;
            if(pq.size()>k)
                pq.pop();
        }
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};