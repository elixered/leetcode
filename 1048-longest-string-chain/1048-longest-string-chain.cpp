class Solution {
public:
    
    bool check(string a,string b)
    {
        int m = a.size();
        int n = b.size();
        if(m-n !=1) return false;
        int diff = 0;
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(a[i]==b[j]) i++,j++;
            else
            {
                diff++;
               i++;
            }
            if(diff>1) return false;
        }
        return true;
    }
    
    static bool comp(string a,string b)
    {
        return a.size()<b.size();
    }
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
       
        int n = words.size();
        vector<int> dp(n,1);
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                 int x = words[i].length(), y = words[j].length();
                if( x==y+1 && check(words[i],words[j]))
                    dp[i] = max(dp[i],1+dp[j]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};