class Solution {
public:
    struct node{
        int idx,freetime,weight;
        node(int a,int b, int c)
        {
            idx = a;
            freetime = b;
            weight = c;
        }
    };
    struct cmp{
        bool operator()(node a, node b)
        {
            if(a.weight == b.weight)
                return a.idx>b.idx;
            else return a.weight>b.weight;
        }
    };
    struct cmp2{
        bool operator()(node a, node b)
        {
            return a.freetime>b.freetime;
        }
    };
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = tasks.size();
        vector<int> ans(n,0);
        priority_queue<node,vector<node>,cmp2> busyQ;
        priority_queue<node,vector<node>,cmp> availQ;
        for(int i=0; i<servers.size(); i++)
        {
            availQ.push(node(i,0,servers[i]));
        }
        int i=0,t=0;
        while(i<n)
        {
            t = max(t,i);
            if(availQ.empty())
            {
                t = busyQ.top().freetime;
            }
            while(!busyQ.empty() && t>=busyQ.top().freetime)
            {
                availQ.push(busyQ.top());
                busyQ.pop();
            }
            auto nd = availQ.top();
            availQ.pop();
            nd.freetime = t+tasks[i];
            busyQ.push(nd);
            ans[i] = nd.idx;
            i++;
        }
        return ans;
    }
};