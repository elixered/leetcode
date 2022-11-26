class Solution {
public:
    // maximum number of jobs are 50000
    int memo[50001];
    
    int findMaxProfit(vector<int>& startTime, vector<vector<int>>& jobs) {
        int length = startTime.size();
        
        for (int position = length - 1; position >= 0; position--) {
            int currProfit = 0;

            int nextIndex = lower_bound(startTime.begin(), startTime.end(), jobs[position][1]) - startTime.begin();
            
            // if there is a non-conflicting job possible add it's profit
            // else just consider the curent job profit
            if (nextIndex != length) {
                currProfit = jobs[position][2] + memo[nextIndex];
            } else {
                currProfit = jobs[position][2];
            }
            
            // storing the maximum profit we can achieve by scheduling 
            // non - conflicting jobs from index i to the end of array
            if (position == length - 1) {
                memo[position] = currProfit;
            } else {
                memo[position] = max(currProfit, memo[position + 1]);
            }
        }
        
        return memo[0];
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> jobs;
        for (int i = 0; i < profit.size(); i++) {
            jobs.push_back({startTime[i], endTime[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        for (int i = 0; i < profit.size(); i++) {
            startTime[i] = jobs[i][0];
        }
        return findMaxProfit(startTime, jobs);
    }
};