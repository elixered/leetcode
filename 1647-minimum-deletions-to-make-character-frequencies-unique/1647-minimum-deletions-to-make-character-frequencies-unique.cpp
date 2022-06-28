class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(auto c:s)
            freq[c-'a']++;
        map<int,int> mp;
        for(auto f:freq){
            if(f)
                mp[f]++;
        }
        int ans = 0;
        for(auto itr=mp.rbegin(); itr != mp.rend(); ++itr){
            while(itr->second > 1){
                int x = itr->first;
                while(x > 0){
                    if(mp.find(x) == mp.end()){
                        mp[x]++;
                        ans += itr->first-x;
                        itr->second -= 1;
                        break;
                    }
                    else x--;
                }
                if(x==0){
                    ans += itr->first*(itr->second-1);
                    itr->second = 1;
                }
            }
        }
        return ans;
    }
};