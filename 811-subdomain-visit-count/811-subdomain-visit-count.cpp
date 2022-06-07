class Solution {
public:
    vector<string> subdomainVisits(vector<string>& domains) {
        unordered_map<string,int> mp;
        for(auto it:domains)
        {
            int n = it.size();
            int i = 0;
            int x = 0;
            vector<int> breakpoints;
            while(i<n && it[i]>='0' && it[i]<='9')
            {
                x = x*10 + it[i]-'0';
                i++;
            }
            cout<<x;
            breakpoints.push_back(i);
            while(i<n)
            {
                if(it[i]=='.')
                    breakpoints.push_back(i);
                i++;
            }
            string prev,curr;
            for(int j=breakpoints.size()-1; j>=0; j--)
            {
                int idx = breakpoints[j]+1;
                if(prev=="")
                {
                    prev = it.substr(idx);
                    mp[prev]+=x;
                }
                else
                {
                    curr = it.substr(idx);
                    mp[curr]+=x;
                    prev = curr;
                    curr = "";
                }
            }
        }
        vector<string>ans;
        for(auto it:mp)
        {
            string s = to_string(it.second)+" "+it.first;
            ans.push_back(s);
        }
        return ans;
    }
};