class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        int i=0,j=0;
        unordered_map<char,int> map;
        for(auto& ch:s1)
            map[ch]++;
        int count = map.size();
        while(j<n)
        {
            if(map.find(s2[j])!=map.end())
            {
                map[s2[j]]--;
                if(map[s2[j]]==0)
                    count--;
            }
            if(j-i+1<m)
            {
                j++;
                continue;
            }
            else
            {
                if(count==0)
                    return true;
                if(map.find(s2[i])!=map.end())
                {
                    map[s2[i]]++;
                    if(map[s2[i]]==1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return false;
    }
};