class Solution {
public:
    
 
    
    vector<int> pancakeSort(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        for(int x=n; x>=1; x--)
        {
            for(int i=0; i<n; i++)
            {
                if(arr[i]==x)
                {
                    ans.push_back(i+1);
                    ans.push_back(x);
                    reverse(arr.begin(),arr.begin()+i+1);
                    reverse(arr.begin(),arr.begin()+x);
                    break;
                }
            }
        }
        
        return ans;
    }
};