class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> score(n);
        score[0] = nums[0];
        deque<int> dq;
        dq.push_back(0);
        for(int i=1; i<n; ++i){
            while(!dq.empty() && dq.front() < i-k)
                dq.pop_front();
            score[i] = score[dq.front()] + nums[i];
            while(!dq.empty() && score[i] >= score[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        return score[n-1];
    }
};