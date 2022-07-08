class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        vector<int> pos(n,0);
        for(int i=0; i<n; ++i)
            pos[row[i]] = i;
        int res = 0;
        for(int i=0; i<n; i+=2){
            int curr = row[i];
            int partner = (curr^1);
            if(row[i+1] == partner) continue;
            int partnerPos = pos[partner];
            res++;
            pos[row[i+1]] = partnerPos;
            swap(row[i+1],row[partnerPos]);
        }
        return res;
    }
};