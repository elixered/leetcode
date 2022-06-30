class Solution {
public:
    #define ll long long
    
    bool equalCount(vector<int>& count){
        int c = 0;
        for(int i=0; i<count.size(); ++i){
            if(count[i]){
                c = count[i];
                break;
            }
        }
        for(int i=1; i<=9; ++i)
            if(count[i] && count[i]!=c) return false;
        return true;
    }
    
    int equalDigitFrequency(string s) {
        int p = 31, m = pow(10,9) + 7;
        int n = s.size();
        vector<ll> p_pow(n);
        p_pow[0] = 1;
        for(int i=1; i<n; ++i)
            p_pow[i] = (p_pow[i-1]*p)%m;
        unordered_map<int,unordered_set<string>> mp;
        vector<ll> hash(n,0);
        for(int i=0; i<n; ++i){
            int curr = (p_pow[i]*(s[i]-'0'+1))%m;
            hash[i] = curr;
            if(i)
                hash[i] = (hash[i] + hash[i-1])%m;
        }
        int ans = 0;
        for(int i=0; i<n; ++i){
            string t;
            vector<int> count(10,0);
            for(int j=i; j<n; ++j){
                t += s[j];
                count[s[j]-'0']++;
                if(equalCount(count)){
                    int h = (hash[j] + m - (i>0 ? hash[i-1]:0))%m;
                    h = (p_pow[n-j-1]*h)%m;
                    if(mp[h].find(t) == mp[h].end()){
                        ans++;
                        mp[h].insert(t);
                    }
                }
            }
        }
        return ans;
    }
};