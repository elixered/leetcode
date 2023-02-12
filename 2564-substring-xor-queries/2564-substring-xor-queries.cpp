class Solution {
public:
    
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& queries) {
        map<int, vector<int>> freq;
        for(int i = 0; i < s.length(); i++){
            long long num = 0;
            for(int j = i, k = 0; j >= 0 && k<=31; j--, k++){
                int bit = s[j]-'0';
                num += (bit<<k);
                vector<int> v = {j, i};
                if(num<INT_MAX && freq.find(num) == freq.end()) {
                    freq[num] = v;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto & i : queries){
            int target = (i[0] ^ i[1]);
            if(freq.find(target) != freq.end()){
                ans.push_back(freq[target]);
            }
            else ans.push_back({-1, -1});
        }
        return ans;
    }
};