class Solution {
public:
    int getMinSwaps(string num, int k) {
        string s = num;
        while(k--)
        {
            next_permutation(s.begin(),s.end());
        }
        int res = 0;
        for(int i=0; i<num.size(); i++)
        {
            if(num[i]!=s[i])
            {
                for(int j=i+1; j<s.size(); j++)
                {
                    if(s[j]==num[i])
                    {
                        for(int k=j; k>i; k--)
                        {
                            swap(s[k],s[k-1]);
                            res++;
                        }
                        break;
                    }
                }
            }
        }
        return res;
    }
};