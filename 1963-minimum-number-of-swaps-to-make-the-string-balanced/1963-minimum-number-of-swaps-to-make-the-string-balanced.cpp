class Solution {
public:
    int minSwaps(string s) {
        int sz = 0;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='[')
                sz++;
            else if(sz>0) sz--;
        }
        return (sz+1)/2;
    }
};