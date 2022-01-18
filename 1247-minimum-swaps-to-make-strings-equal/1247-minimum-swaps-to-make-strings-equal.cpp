class Solution {
public:
    int minimumSwap(string s1, string s2) {
       int xy=0,yx=0;
        for(int i=0; i<s1.size(); i++)
        {
            if(s1[i]==s2[i])
                continue;
            if(s1[i]=='x')
                xy++;
            else yx++;
        }
        cout<<xy<<" "<<yx;
        int swaps = 0;
        swaps += (xy/2);
        xy %= 2;
        swaps += (yx/2);
        yx %= 2;

        if(xy!=yx) return -1;
        return swaps+(xy==0?0:2);
    }
};