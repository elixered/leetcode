class Solution {
public:
    
    bool check(vector<int>& temp)
    {
        int k = temp.size()-1;
        int mini = *min_element(temp.begin(),temp.end());
        int maxi = *max_element(temp.begin(),temp.end());
        if(mini==maxi) return true;
        if((maxi-mini)%k!=0) return false;
        int diff = (maxi-mini)/k;
        unordered_set<int> set;
        for(int i=0; i<k; i++)
            set.insert(i);
        for(auto it:temp)
        {
            if((it-mini)%diff !=0) return false;
            if(set.find((it-mini)/diff)!=set.end())
                set.erase(set.find((it-mini)/diff));
        }
        return set.size()==0;
    }
    
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = nums.size();
        int m = r.size();
        vector<bool> ans(m,0);
        for(int i=0; i<m; i++)
        {
            if(r[i]-l[i]+1<2)
            {
                ans[i] = false;
                continue;
            }
            vector<int> temp;
            for(int j=l[i]; j<=r[i]; j++)
            {
                temp.push_back(nums[j]);
            }
            ans[i] = check(temp);
        }
        return ans;
    }
};