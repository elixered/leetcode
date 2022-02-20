class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        unordered_map<long long,long long> res_cnt;
        for(int num:nums){
            res_cnt[num%k]++;
        }
        long long ret = 0;
        for(auto [n1,c1]:res_cnt){

            long long g = gcd(n1,(long long)(k));
            long long another = k/g;
            if(n1==0){
                long long l = nums.size();
                ret += c1*(l-c1) + c1*(c1-1)/2;
                continue;
            }            
            
            for(long long n2=another;n2<k;n2+= another){
                if(n2<n1){
                    continue;
                }

                if(n2==n1){
                    ret += c1*(c1-1)/2;
                    continue;
                }
                if(res_cnt.count(n2)==0){
                    continue;
                }
                ret += c1*res_cnt.at(n2);
            }
        }
        return ret;
    }
};