class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        vector<int> visited(n,0);
        int ans = 0;
        for(int i=0; i<n; i++){
            int count = 0;
            int j = i;
            while(!visited[j]){
                count++;
                visited[j] = 1;
                j = nums[j];
            }
            ans = max(ans,count);
        }
        return ans;
    }
};