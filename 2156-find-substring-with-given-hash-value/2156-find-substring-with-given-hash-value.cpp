class Solution {
public:
  string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        int n = s.size();
        long curhash = 0;
        long computed = 1;
        for(int i=0; i<k-1; ++i)
            computed = computed*power%modulo;
        
        string ret;
        for(int i=n-1; i>=0; --i){
            if(i < n-k){
                curhash = (curhash - (s[i+k]-'a'+1) * computed) % modulo;
                if(curhash < 0)
                    curhash += modulo;
            }
            curhash = (curhash*power + s[i]-'a'+1)%modulo;
            
            if(i<=n-k && hashValue == curhash)
                ret = s.substr(i, k);
        }
        return ret;   
    }
};