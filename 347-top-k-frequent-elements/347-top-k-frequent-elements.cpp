class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> freq[n+1];
        unordered_map<int,int> hm;
        for(int i=0; i<n; i++)
            hm[nums[i]]++;
        for(auto it:hm)
            freq[it.second].push_back(it.first);
        int count = 0;
        vector<int> res;
        for(int i=n; i>0;i--)
        {
            for(auto x:freq[i])
            {
                res.push_back(x);
                count++;
                if(count==k) return res;;
            }
        }
        return res;
    }
};