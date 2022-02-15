class Solution {
public:
    # define ll long long
    long long numberOfWeeks(vector<int>& nums) {
        ll poora = 0;
        poora = accumulate(nums.begin(),nums.end(),poora);
        ll sabseBada = *max_element(nums.begin(),nums.end());
        ll baaki = poora - sabseBada;
        if(sabseBada>baaki)
            return 2*baaki+1;
        else return poora;
    }
};