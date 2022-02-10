class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int count = 0;
        unordered_map<char,int> map;
        int unique = 0;
        int n = s.size();
        unordered_map<string,int> hm;
        for(int k=minSize; k<=maxSize; k++)
        {
            int i = 0;
            int j = 0;
            while(j<n)
            {
                map[s[j]]++;
                if(map[s[j]]==1)
                    unique++;
                if(j-i+1<k)
                {
                    j++;
                    continue;
                }
                else
                {
                    if(unique<=maxLetters)
                    {
                        hm[s.substr(i,k)]++;
                        count++;
                    }
                    map[s[i]]--;
                    if(map[s[i]]==0)
                        unique--;
                    i++;
                    j++;
                }
            }
        }
        int maxi = 0;
        for(auto& it:hm)
            maxi = max(maxi,it.second);
        return maxi;
    }
};