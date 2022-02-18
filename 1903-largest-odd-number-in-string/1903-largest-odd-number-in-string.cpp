class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        int idx = -1;
        for(int i=n-1; i>=0; i--)
        {
            int x = num[i]-'0';
            if(x%2!=0)
            {
                idx = i;
                break;
            }
        }
        if(idx<0) return "";
        return string(num.begin(),num.begin()+idx+1);
    }
};