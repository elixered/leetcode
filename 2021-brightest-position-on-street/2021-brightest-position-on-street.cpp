class Solution {
public:
    int brightestPosition(vector<vector<int>>& lights) {
        map<int,int> mp;
        for(auto p:lights){
            mp[p[0]-p[1]]++;
            mp[p[0]+p[1]+1]--;
        }
        int ans = 0;
        int point = 0;
        int sum = 0;
        for(auto it:mp){
            sum += it.second;
            if(ans < sum){
                ans = sum;
                point = it.first;
            }
        }
        return point;
    }
};