class Solution {
public:
    
    int longestWPI(vector<int>& hours) {
        for(auto& it:hours){
            if(it > 8) it = 1;
            else it = -1;
        }
        int ans = 0;
        map<int,int> mp;
        mp[0] = -1;
        int count = 0;
        for(int i=0; i<hours.size(); ++i){
            count += hours[i];
            if(count > 0)
                ans = max(ans,i+1);
            else
            if(mp.find(count-1) != mp.end())
                ans = max(ans,i-mp[count-1]);
            if(mp.find(count) == mp.end())
                mp[count] = i;
        }
        return ans;
    }
};