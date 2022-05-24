class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string w) {
        vector<vector<string>> ans;
        multiset<string> wordset(products.begin(),products.end());
        string s;
        for(auto c:w)
        {
            s.push_back(c);
            int idx = s.size()-1;
            vector<string> v;
            for(auto it=wordset.begin(); it!=wordset.end(); )
            {
                string curr = *it;
                if(curr.size()<s.size() or curr[idx]!=s[idx]) 
                {
                    auto nex = next(it);
                    wordset.erase(it);
                    it = nex;
                }
                else
                {
                    if(v.size()<3)
                    v.push_back(curr);
                    it++;
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};