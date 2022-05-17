class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int end = 0;
        int maxreach = 0;
        int count = 0;
        int n = clips.size();
        for(int i=0; end<time; end = maxreach)
        {
            count++;
            while(i<n && clips[i][0]<=end)
            {
                maxreach = max(maxreach,clips[i++][1]);
            }
            if(end==maxreach)
                return -1;
        }
        return end<time?-1:count;
    }
};