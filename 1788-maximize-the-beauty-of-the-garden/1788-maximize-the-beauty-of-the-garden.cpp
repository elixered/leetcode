class Solution {
public:
int maximumBeauty(vector<int>& flowers) {
        unordered_map<int,int>mp;
        int sum = 0;
        int presum = 0;
        int res = INT_MIN;
        for(auto &x : flowers){
            sum += max(x,0);
            if(mp.find(x) != mp.end()){
                res = max(res,presum-mp[x] + 2 * x);
            }
            else{
                mp[x] = sum;
            }
            presum = sum;
        }
        return res;
    }
};