class Solution {
public:
    bool isvowel(char& ch) { return (ch == 'a') || (ch == 'e') ||(ch == 'i') ||(ch == 'o') ||(ch == 'u'); }
    
    int reverse(int& count, int idx)
    {
        return (count^(1<<idx));
    }
    
    int findTheLongestSubstring(string& s) {
        int n = s.size();
        unordered_map<int,int> map;
        unordered_map<char,int> value;
        value['a'] = 0; value['e'] = 1; value['i'] = 2;
        value['o'] = 3; value['u'] = 4;
        map[0] = -1;
        int maxLen = 0;
        int count = 0;
        for(int i=0; i<n; i++)
        {
            int idx = value[s[i]];
            if(isvowel(s[i]))
            count = reverse(count,idx);
            if(map.find(count)==map.end())
                map[count] = i;
            else
                maxLen = max(maxLen,i-map[count]);
        }
        return maxLen;
    }
};