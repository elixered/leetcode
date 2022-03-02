class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0);
        
        for(int i=0,cnt=0,sum=0; i<n; i++)
        {
            cnt += (boxes[i]-'0');
            sum += (boxes[i]=='1' ? i:0);
            ans[i] += i*cnt - sum;
        }
        
        for(int i=n-1,cnt=0,sum=0; i>=0; i--)
        {
            cnt += (boxes[i]-'0');
            sum += (boxes[i]=='1' ? i:0);
            ans[i] += sum - cnt*i;
        }
        
        return ans;
    }
};