class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        string s(m+n,'0');
        int counter = 0;
        for(int i=m-1; i>=0; i--)
        {
            int idx = m+n-1-counter;
            int carry = 0;
            int multiplier = num1[i]-'0';
            for(int j=n-1; j>=0; j--)
            {
                int sum = (num2[j]-'0')*multiplier+carry+s[idx]-'0';
                carry = sum/10;
                s[idx] = (char)(sum%10+'0');
                idx--;
            }
            while(carry>0)
            {
                int sum = s[idx]-'0'+carry;
                carry = sum/10;
                s[idx] = (char)(sum%10+'0');
                idx--;
            }
            counter++;
        }
        int zero = 0;
        while(zero<m+n && s[zero]=='0')
            zero++;
        if(zero==m+n)
            return "0";
        return string(s.begin()+zero,s.end());
    }
};