class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if(k<1 or k>n) return false;
        if(k==n) return true;
        vector<int> hm(26,0);
        for(auto& ch:s)
            hm[ch-'a']++;
        int oddCount = 0;
        int evenCount = 0;
        for(auto& it:hm)
            if(it%2!=0)
                oddCount++;
            else evenCount++;
        int leastPossible = oddCount;
        return leastPossible <= k;
    }
};