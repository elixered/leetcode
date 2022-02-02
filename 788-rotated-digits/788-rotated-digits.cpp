class Solution {
public:
    bool canReverse(string s)
    {
        for(auto& ch:s)
        {
            if(ch=='3' or ch=='4' or ch=='7')
                return false;
        }
        return true;
    }
    char get(char x)
    {
        if(x=='0' or x=='1' or x=='8')
            return x;
        if(x=='2') return '5';
        if(x=='5') return '2';
        if(x=='6') return '9';
        if(x=='9') return '6';
        return '7';
    }
    int reverse(string s)
    {
        string ans;
        for(auto& ch:s)
            ans += get(ch);
        return stoi(ans);
    }
    
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1; i<=n; i++)
        {
            if(!canReverse(to_string(i)))
                continue;
            if(reverse(to_string(i))==i)
                continue;
            count++;
        }
        return count;
    }
};