class Solution {
public:
    #define ll long long
    int p = 31, m = pow(10,9)+7;
    
    ll hash(string& s, vector<ll>& p_pow){
        ll h = 0;
        for(int i=0; i<s.size(); ++i){
            h += ((s[i]-'a'+1)*p_pow[i])%m;
        }
        return h;
    }
    
    bool differByOne(vector<string>& dict) {
        int n = dict[0].size();
        
        vector<ll> p_pow(n);
        p_pow[0] = 1;
        for(int i=1; i<n; ++i)
            p_pow[i] = (p_pow[i-1]*p)%m;
        
        vector<ll> hashes(dict.size());
        for(int i=0; i<dict.size(); ++i){
            string& s = dict[i];
            hashes[i] = hash(s,p_pow);
        }
        
        for(int i=n-1; i>=0; i--){
            unordered_map<int,vector<int>> mp;
            for(int j=0; j<dict.size(); ++j){
                int h = (m + hashes[j] - p_pow[i]*(dict[j][i]-'a'+1)%m)%m;
                auto it = mp.find(h);
                if(it != mp.end()){
                    return true;
                }
                mp[h].push_back(j);
            }
        }
        return false;
    }
};