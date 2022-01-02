class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size();
        for(auto& it:time)
            it = it%60;
        int ans = 0;
        sort(time.begin(),time.end());
        int i=0;
        while(i<n && time[i]==0)
            i++;
        ans += (i*(i-1))/2;
        unordered_map<int,int> map;
        for(i; i<n; i++)
        {
            ans += map[60-time[i]];
            map[time[i]]++;
        }
        return ans;
    }
};