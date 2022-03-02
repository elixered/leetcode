class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        int rc = 0, dc = 0;
        for(auto c:senate)
        {
            if(c=='D')
                dc++;
            else rc++;
        }
        if(rc==0) return "Dire";
        if(dc==0) return "Radiant";
        vector<int> vis(n,0);
        while(true)
        {
        for(int i=0; i<n; i++)
        {
            if(!vis[i])
        {
            if(senate[i]=='D')
            {
                int j = (i+1)%n;
                while(j!=i && (senate[j]!='R' or vis[j]))
                    j = (j+1)%n;
                if(j!=i)
                {
                    vis[j] = 1;
                    rc--;
                }
            }
            else
            {
                int j = (i+1)%n;
                while(j!=i && (senate[j]!='D' or vis[j]))
                    j = (j+1)%n;
                if(j!=i)
                {
                    vis[j] = 1;
                    dc--;
                }
            }
        }
            if(rc==0) return "Dire";
            if(dc==0) return "Radiant";
        }
        }
        return "fg";
    }
};