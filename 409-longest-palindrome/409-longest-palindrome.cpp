class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> map;
        int count = 0;
        for(auto& c:s)
        {
            if(map[c]>0)
            {
                count+=2;
                map[c]--;
            }
            else
                map[c]++;
        }
        bool flag = false;
        for(auto it:map)
        {
            if(it.second==1)
            {
                flag = true;
                break;
            }
        }
        return flag==true?count+1:count;
    }
};