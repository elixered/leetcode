class Solution {
public:
    string predictPartyVictory(string senate) {
        int rad = 0, dire = 0;
        int disabledRad = 0, disabledDire = 0;
        for(auto c:senate)
        {
            if(c=='D')
                dire++;
            else rad++;
        }
        vector<int> vis(senate.size(),0);
while(true){
        for(int i=0; i<senate.size(); i++)
        {
            char it = senate[i];
            if(!vis[i])
            {
            if(it=='D')
            {
                if(disabledDire>0)
                {
                    disabledDire--;
                    vis[i] = 1;
                }
                else
                {
                    disabledRad++;
                    rad--;
                }
            }
            else
            {
                if(disabledRad>0)
                {
                    disabledRad--;
                    vis[i] = 1;
                }
                else
                {
                    disabledDire++;
                    dire--;
                }
            }
            }
            if(dire<=0) return "Radiant";
            if(rad<=0) return "Dire";
        }
}
        return "LOL";
    }
};