class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int m = nums.size();
        int index = 0;
        for(auto group : groups){
            int n = group.size();
            vector<int>lps(n,0);
            for(int i = 1;i<n; i++){
                int j = lps[i-1];
                while(j>0 && group[i] != group[j]){
                    j = lps[j-1];
                }
                if(group[i] == group[j]){
                    j++;
                }
                lps[i] = j;
            }            
            int j = 0;
            while(index<m){
                if(nums[index]==group[j]){
                    j++;
                    index++;
                }
                if(j==n)
                    break;
                else
                 if(index <m && nums[index] != group[j]){
                    if(j >0){
                        j=lps[j-1];
                    }else{
                        index++;
                    }
                }
            }
            if(j != n)
                return false;
        }
        
        return true;
    }
};