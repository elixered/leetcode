class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> first(26,-1);
        vector<int> last(26,-1);
        int n = s.size();
        for(int i=0; i<n; i++)
        {
            int c = s[i]-'a';
            if(first[c]==-1)
                first[c] = i;
            last[c] = i;
        }
        vector<int> ans;
        for(int i=0; i<n; i++)
        {
            int c = s[i]-'a';
            int lastIdx = last[c];
            int j = i;
            while(j<lastIdx)
            {
                int currLast = last[s[j]-'a'];
                lastIdx = max(lastIdx,currLast);
                j++;
            }
            ans.push_back(j-i+1);
            i = j;
        }
        return ans;
    }
};