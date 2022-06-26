class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slot1, vector<vector<int>>& slot2, int duration) {
        sort(begin(slot1),end(slot1));
        sort(begin(slot2),end(slot2));
        int m = slot1.size();
        int n = slot2.size();
        int i = 0, j = 0;
        while(i < m && j < n){
            if(slot1[i][0] > slot2[j][1])
                j++;
            else if(slot1[i][1] < slot2[j][0])
                i++;
            else{
                int stime = max(slot1[i][0],slot2[j][0]);
                int etime = min(slot1[i][1],slot2[j][1]);

                if(etime-stime >= duration)
                    return {stime,stime+duration};
                else{
                    slot1[i][1] <= slot2[j][1] ? i++:j++;
                }
            }
        }
        return {};
    }
};