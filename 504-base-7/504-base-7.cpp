class Solution {
public:
    string convertToBase7(int num) {
        bool neg = false;
        if(num<0) neg = true;
        num = abs(num);
        string s = "";
        do
        {
            s += to_string(num%7);
            num /= 7;
        }while(num);
        reverse(s.begin(),s.end());
        return neg==true?"-"+s:s;
    }
};