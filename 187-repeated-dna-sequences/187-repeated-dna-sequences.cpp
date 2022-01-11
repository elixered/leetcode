class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        unordered_map<string,int> umap;
        int i=0,j=0;
        string hash;
        while(j<s.size())
        {
            hash.push_back(s[j]);
            if(hash.size()<10) j++;
            else
            {
                umap[hash]++;
                hash.erase(hash.begin());
                i++;
                j++;
            }
        }
        
        vector<string> ans;
        for(auto it:umap)
        {
            if(it.second > 1)
                ans.push_back(it.first);
        }
        
        return ans;
        
    }
};