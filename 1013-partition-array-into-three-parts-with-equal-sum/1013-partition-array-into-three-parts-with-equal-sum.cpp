class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum = 0;
        for(auto& it:arr)
            sum += it;
        if(sum%3!=0) return false;
        sum = sum/3;
        int curr = 0;
        int count = 0;
        for(int i=0; i<arr.size(); i++)
        {
            if(count==2) return true;
            curr += arr[i];
            if(curr==sum)
            {
                curr = 0;
                count++;
            }
        }
        return false;
    }
};