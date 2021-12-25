class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:sticks)
            pq.push(it);
        int ans = 0;
        while(pq.size()!=1)
        {
            auto first = pq.top();
            pq.pop();
            auto second = pq.top();
            pq.pop();
            pq.push(first+second);
            ans += first+second;
        }
        return ans;
    }
};