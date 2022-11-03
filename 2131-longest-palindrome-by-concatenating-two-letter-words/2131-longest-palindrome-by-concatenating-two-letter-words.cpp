class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> map;
        int count = 0;
        for(auto s:words)
        {
            string t = s;
            reverse(t.begin(),t.end());
            if(map[t]>0)
            {
                count += 4;
                map[t]--;
            }
            else
                map[s]++;
        }
        bool flag = false;
        for(auto it:map)
        {
            if(it.second==1 && it.first[0]==it.first[1])
            {
                flag = true;
                break;
            }
        }
        return flag == true ? count+2:count;
    }
};