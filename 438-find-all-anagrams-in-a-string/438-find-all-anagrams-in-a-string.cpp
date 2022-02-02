class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n = s.size(), k = p.size();
        if(k>n) return ans;
        int left =0, right = 0;
        unordered_map<char,int> hm;
        for(auto c:p)
            hm[c]++;
        int count = hm.size();
        
        while(right<n)
        {
            char c = s[right];
            if(hm.find(c) != hm.end())
            {
                hm[c]--;
                if(hm[c]==0) count--;
            }
            if(right-left+1<k)
            {
                right++;
                continue;
            }
            else
            {
                if(count==0)
                    ans.push_back(left);
                char b = s[left];
                if(hm.find(b)!=hm.end())
                {
                    hm[b]++;
                    if(hm[b]==1)
                        count++;
                }
                left++;
                right++;
            }
        }
        return ans;
    }
};