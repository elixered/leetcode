class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double,int> mp;
        for(auto r:rectangles){
            double ratio = (double)r[0]/(double)r[1];
            mp[ratio]++;
        }
        long long ans = 0;
        for(auto it:mp){
            long long n = it.second;
            ans += n*(n-1)/2;
        }
        return ans;
    }
};