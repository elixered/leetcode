class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto it:tasks)
            mp[it]++;
        int steps = 0;
        for(auto it:mp){
            if(it.second < 2) return -1;
            int x = it.second;
            if(x % 3 == 1){
                steps += (x-4)/3 + 2;
            }
            else{
                steps += x/3;
                x %= 3;
                steps += x/2;
            }
        }
        return steps;
    }
};