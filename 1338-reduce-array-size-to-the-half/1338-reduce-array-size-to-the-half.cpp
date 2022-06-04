class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> ump;
        for(auto it:arr)
            ump[it]++;
        vector<int> freq(arr.size()+1,0);
        for(auto it:ump)
            freq[it.second]++;
        int target = (arr.size()+1)/2;
        int ans = 0;
        for(int i=arr.size(); i>0; i--)
        {
            if(freq[i]>0)
            {
                if(target-i*freq[i]>=0)
                {
                    ans += freq[i];
                    target -= i*freq[i];
                }
                else
                {
                    int req = ceil((float)target/i);
                    return ans+req;
                }
            }
            if(target<=0) return ans;
        }
        return ans;
    }
};