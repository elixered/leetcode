class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        unordered_map<int,int> hm;
        for(auto& it:t)
            hm[it]++;
        int count = hm.size();
        int i=0,j=0;
        string ans = "";
        int idx = -1, mini = m;
        while(j<m)
        {
            char a = s[j];
            if(hm.find(a)!=hm.end())
            {
                hm[a]--;
                if(hm[a]==0)
                    count--;
            }
            while(count==0 && i<=j)
            {
                if(j-i+1<=mini)
                {
                    idx = i;
                    mini = j-i+1;
                }
                char b = s[i];
                if(hm.find(b)!=hm.end())
                {
                    hm[b]++;
                    if(hm[b]>0)
                        count++;
                }
                i++;
            }
            j++;
        }
        if(idx==-1) return "";
        return s.substr(idx,mini);
    }
};