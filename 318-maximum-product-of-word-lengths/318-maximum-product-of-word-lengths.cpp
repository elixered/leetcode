class Solution {
public:
    
    int match(int a, int b)
    {
        return (a&b)!=0;
    }
    
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> ans;
        for(auto s:words)
        {
            int x = 0;
            for(auto c:s)
            {
                x = (x|(1<<(c-'a')));
            }
            ans.push_back(x);
        }
        int res = 0;
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(match(ans[i],ans[j])==false)
                    res = max(res,(int)words[i].size()*(int)words[j].size());
            }
        }
        return res;
    }
};