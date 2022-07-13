class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
         vector<int> owed(21, 0);
        for(vector<int>& t: transactions){
            int a = t[0], b = t[1];
            owed[a] += t[2];
            owed[b] -= t[2];
        }
        vector<int> nonzero;
        for(int o : owed){
            if(o != 0){
                nonzero.push_back(o);
            }
        }
        owed = nonzero;
        int N = owed.size();
        
        vector<int> maxSets(1<<N); 
        vector<int> sum(1<<N); 
        for(int mask = 0; mask < 1<<N; mask++){
            for(int bitNo = 0; bitNo < N; bitNo++){
                int bit = 1<<bitNo;
                int next = mask | bit;
                if(mask == next){
                    continue;
                }
                sum[next] = sum[mask]+owed[bitNo];
                if(sum[next] == 0){
                    maxSets[next] = max(maxSets[next], maxSets[mask]+1);
                } else {
                    maxSets[next] = max(maxSets[next], maxSets[mask]);
                }
            }
        }
        
        return N-maxSets[(1<<N) - 1];
    }
};