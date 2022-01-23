class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> all;
        queue<long> q;
        for(int i=1; i<=8; i++)
        {
            q.push(i);
        }
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            all.push_back(curr);
            int rem = curr%10;
            if(rem==9) continue;
            curr = curr*10+rem+1;
            if(curr<=high)
            q.push(curr);
        }
        vector<int> ans;
        for(auto it:all)
            if(it>=low and it<=high)
                ans.push_back((int)it);
        sort(ans.begin(),ans.end());
        return ans;
    }
};