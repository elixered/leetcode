class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> leftcount(n,0),rightcount(n,0),leftsum(n,0),rightsum(n,0);
        if(boxes[0]=='1')
        {
            leftcount[0] = 1;
        }
        if(boxes[n-1]=='1')
        {
            rightcount[n-1] = 1;
            rightsum[n-1] = n-1;
        }
        for(int i=1; i<n; i++)
        {
            leftcount[i] = leftcount[i-1] + (boxes[i]-'0');
            leftsum[i] += leftsum[i-1] + (boxes[i]=='1' ? i:0);
        }
        for(int i=n-2; i>=0; i--)
        {
            rightcount[i] = rightcount[i+1] + (boxes[i]-'0');
            rightsum[i] = rightsum[i+1] + (boxes[i]=='1' ? i:0);
        }
        vector<int> ans(n,0);
        for(int i=0; i<n; i++)
        {
            int lcount = (i>0?leftcount[i-1]:0);
            int lsum = (i>0?leftsum[i-1]:0);
            int rcount = (i<n-1?rightcount[i+1]:0);
            int rsum = (i<n-1?rightsum[i+1]:0);
            ans[i] = rsum - i*rcount + (i*lcount-lsum);
        }
        return ans;
    }
};