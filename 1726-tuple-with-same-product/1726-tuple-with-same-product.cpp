class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; ++i){
            for(int j=i+1; j<n; j++){
                mp[nums[i]*nums[j]]++;
            }
        }
        int ans = 0;
        for(auto& it:mp){
            auto vec = it.second;
            ans += 4*vec*(vec-1);
        }
        return ans;
    }
};