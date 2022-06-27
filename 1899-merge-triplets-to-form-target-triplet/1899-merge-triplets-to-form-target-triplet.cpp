class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        sort(begin(triplets),end(triplets));
        int n1 = 0;
        int n2 = 0;
        int n3 = 0;
        int t1 = target[0], t2 = target[1], t3 = target[2];
        for(int i=0; i<triplets.size(); i++){
            if(triplets[i][0] > t1 or triplets[i][1] > t2 or triplets[i][2] > t3) 
                continue;
            n1 = max(n1,triplets[i][0]);
            n2 = max(n2,triplets[i][1]);
            n3 = max(n3,triplets[i][2]);
            if(n1==t1 && n2==t2 && n3==t3) return true;
        }
        return false;
    }
};