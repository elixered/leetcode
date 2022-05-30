class Solution {
public:
    struct node{
        int idx;
        int enq;
        int proc;
        node(int a, int b, int c)
        {
            idx = a;
            enq = b;
            proc = c;
        }
    };
    struct cmp{
        bool operator()(node a, node b)
        {
            return a.enq > b.enq;
        }
    };
    struct cmp2{
        bool operator()(node a, node b)
        {
            if(a.proc > b.proc) return true;
            if(a.proc < b.proc) return false;
            return a.idx > b.idx;
        }
    };
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<node,vector<node>,cmp> pq;
        priority_queue<node,vector<node>,cmp2> avail;
        int n = tasks.size();
        for(int i=0; i<n; i++)
        {
            pq.push(node(i,tasks[i][0],tasks[i][1]));
        }
        vector<int> ans;
        long long t = 0;
        while(!pq.empty() or !avail.empty())
        {
            if(avail.empty() && t<pq.top().enq)
                t = pq.top().enq;
            while(!pq.empty() && pq.top().enq<=t)
            {
                avail.push(pq.top());
                pq.pop();
            }
            if(!avail.empty())
            {
                ans.push_back(avail.top().idx);
                if(avail.top().enq > t)
                    t = avail.top().enq;
                t += avail.top().proc;
                avail.pop();
            }
            else if(!pq.empty())
            {
                ans.push_back(pq.top().idx);
                if(pq.top().enq > t)
                    t = pq.top().enq;
                t += pq.top().proc;
                pq.pop();
            }
        }
        return ans;
    }
};