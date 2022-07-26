class Solution {
public:
    string fractionToDecimal(int num, int deno) {
        if(!num)
            return "0";
        string ans;
        if((num>0)^(deno>0))
            ans += "-";
        long n = labs(num), d = labs(deno), r = n % d;
        ans += to_string(n / d);
        if(!r)
            return ans;
        ans += ".";
        unordered_map<long,int> res;
        while(r){
            if(res.find(r) != res.end()){
                ans.insert(res[r],"(");
                ans += ")";
                break;
            }
            else{
                res[r] = ans.size();
                r *= 10;
                ans += to_string(r / d);
                r %= d;
            }
        }
        return ans;
    }
};