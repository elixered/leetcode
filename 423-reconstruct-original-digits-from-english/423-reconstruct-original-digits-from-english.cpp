class Solution {
public:
    string originalDigits(string s) {
        string ans;
        map<char,int> mp;
        for(auto c:s)
            mp[c]++;
        ans.append(mp['z'],'0');
        int x = mp['z'];
        for(auto i:"zero")
            mp[i] -= x;
        ans.append(mp['w'],'2');
        x = mp['w'];
        for(auto i:"two")
            mp[i] -= x;
        ans.append(mp['u'],'4');
        x = mp['u'];
        for(auto i:"four")
            mp[i] -= x;
        ans.append(mp['x'],'6');
        x = mp['x'];
        for(auto i:"six")
            mp[i] -= x;
        ans.append(mp['g'],'8');
        x = mp['g'];
        for(auto i:"eight")
            mp[i] -= x;
        ans.append(mp['o'],'1');
        x = mp['o'];
        for(auto i:"one")
            mp[i] -= x;
        ans.append(mp['r'],'3');
        x = mp['r'];
        for(auto i:"three")
            mp[i] -= x;
        ans.append(mp['f'],'5');
        x = mp['f'];
        for(auto i:"five")
            mp[i] -= x;
        ans.append(mp['s'],'7');
        x = mp['s'];
        for(auto i:"seven")
            mp[i] -= x;
        ans.append(mp['i'],'9');
        x = mp['i'];
        for(auto i:"nine")
            mp[i] -= x;
        sort(ans.begin(),ans.end());
        return ans;
    }
};