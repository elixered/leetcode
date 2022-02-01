class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n = target.size();
        if(n==1)
            return target[0] == 1;
        long long sum = 0;
        priority_queue<int> pq;
        for(int i=0; i<target.size(); i++)
        {
            int it = target[i];
            pq.push(it);
            sum += it;
        }
        while(pq.top()!=1)
        {
            long first = pq.top();
            pq.pop();
            long rest = sum-first;
            if(rest==1) return true;
            long element = first-rest;
            if(element<=0) return false;
            if(element%(rest)<=0) return false;
            pq.push(element%(rest));
            sum += element%rest - first;
        }
        while(!pq.empty())
        {
            if(pq.top()!=1) return false;
            pq.pop();
        }
            return true;
    }
};