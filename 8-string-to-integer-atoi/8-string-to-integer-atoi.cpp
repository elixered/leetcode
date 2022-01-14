class Solution {
public:
    int myAtoi(string s) {
        int n  = s.size();
        int i=0;
        while(i<n && s[i]==' ')
            i++;
        int ans = 0;
        if(i==n)
            return 0;
        bool isPositive = true;
        if(s[i]=='-')
        {
            isPositive = false;
            i++;
        }
        else if(s[i]=='+')
        {
            i++;
            isPositive = true;
        }
        else if(!isdigit(s[i]))
            return 0;

        while(i<n && isdigit(s[i]))
        {
            if(ans==0)
            {
                if(isPositive==true)
                    ans = s[i]-'0';
                else
                    ans = -(s[i]-'0');
            }
            else
            if(ans>0)
            {
                if(ans>INT_MAX/10)
                    return INT_MAX;
                if(ans==INT_MAX/10 && (s[i]-'0')>7)
                    return INT_MAX;
                ans = ans*10+(s[i]-'0');
            }
            else if(ans<0)
            {
                if(ans<INT_MIN/10)
                    return INT_MIN;
                if(ans==INT_MIN/10 && (s[i]-'0')>8)
                    return INT_MIN;
                ans = ans*10-(s[i]-'0');
            }
            i++;
        }
        return ans;
    }
};