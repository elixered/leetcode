class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        if(n<10) return n;
        string s = to_string(n);
        int sz = s.size();
        for(int i=1; i<sz; i++)
        {
            char curr = s[i];
            char prev = s[i-1];
            if(curr>=prev)
                continue;
            else
            {
                int idx = i-1;
                while(idx>=0 && s[idx]==s[i-1])
                    idx--;
                idx++;
                s[idx]--;
                for(int j=idx+1; j<sz; j++)
                    s[j] = '9';
                break;
            }
        }
        return stoi(s);
    }
};