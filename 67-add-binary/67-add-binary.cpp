class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        string ans;
        int carry = 0;
        int i=m-1,j=n-1;
        while(i>=0 || j>=0 || carry>0)
        {
            if(i>=0) carry += (a[i--]-'0');
            if(j>=0) carry += (b[j--]-'0');
            ans += to_string(carry%2);
            carry /= 2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};