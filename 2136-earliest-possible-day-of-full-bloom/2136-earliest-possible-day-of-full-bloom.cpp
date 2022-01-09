class Solution {
public:
    struct node{
        int pt,gt;
        node(int p, int g)
        {
            pt = p;
            gt = g;
        }
    };
    struct cmp{
        bool operator()(node n1,node n2)
        {
            return n1.gt<n2.gt;
        }
    };
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        int curr = 0;
        int ans = 0;
        priority_queue<node,vector<node>,cmp> pq;
        for(int i=0; i<n; i++)
        {
            pq.push(node(plantTime[i],growTime[i]));
        }
        while(!pq.empty())
        {
            int maxtime = curr + pq.top().pt + pq.top().gt;
            ans = max(ans,maxtime);
            curr += pq.top().pt;
            pq.pop();
        }
        return ans;
    }
};