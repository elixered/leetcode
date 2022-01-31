class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = typed.size();
        int n = name.size();
        int i=0,j=0;
        while(i<m && j<n)
        {
            if(typed[i]==name[j])
            {
                i++;
                j++;
            }
            else
            {
                if(i==0) return false;
                if(typed[i]!=typed[i-1])
                    return false;
                i++;
            }
        }
        while(i<m)
        {
            if(typed[i]!=typed[i-1])
                return false;
            i++;
        }
        return j>=n;
    }
};