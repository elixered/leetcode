class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<nums.size(); ++i){
            int it = nums[i];
            if(mp.find(it) == mp.end()){
                mp[it] = {1,i,i};
            }
            else{
                mp[it] = {mp[it][0]+1,mp[it][1],i};
            }
        }
        int maxfreq = -1, maxlen = INT_MAX;
        for(auto it:mp){
            auto v = it.second;
            if(v[0] >= maxfreq){
                int currlen = v[2]-v[1]+1;
                if(maxfreq < v[0]){
                    maxfreq = v[0];
                    maxlen = currlen;
                }
                else if(maxfreq == v[0])
                    maxlen = min(maxlen,currlen);
            }
        }
        return maxlen;
    }
};