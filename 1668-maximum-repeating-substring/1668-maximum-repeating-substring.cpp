class Solution {
public:
    int maxRepeating(string s, string w) {
        int n = s.size();
        string temp = w;
        int m = w.size();
        while(w.size() < n)
            w += temp;
        string t = w + "#" + s;
        int k = t.size();
        vector<int> lps(k,0);
        for(int i=1; i<k; ++i){
            int j = lps[i-1];
            while(j && t[i] != t[j])
                j = lps[j-1];
            if(t[i] == t[j])
                j++;
            lps[i] = j;
        }
        int ans = 0;
        for(int i=w.size()+1; i<k; ++i){
            if(lps[i]%m == 0)
                ans = max(ans,lps[i]/m);
        }
        return ans;
    }
};