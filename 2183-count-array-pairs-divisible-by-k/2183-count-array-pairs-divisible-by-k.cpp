class Solution {
public:
    long long coutPairs(vector<int>& nums, int k) {
        unordered_map<long long,long long> map;
        for(auto it: nums)
        {
            map[it%k]++;
        }
        long long res = 0;
        for(auto [n1,c1]: map)
        {
            long long g = gcd(n1,(long long)k);
            long long another = k/g;
            if(n1==0)
            {
                long long l = nums.size();
                res += c1*(l-c1) + c1*(c1-1)/2;
                continue;
            }
            for(long long n2=another; n2<k; n2+=another)
            {
                if(n2<n1)
                    continue;
                if(n2==n1)
                {
                    res += c1*(c1-1)/2;
                }
                else if(map.find(n2)!=map.end())
                    res += c1*map[n2];
            }
        }
        return res;
    }
};