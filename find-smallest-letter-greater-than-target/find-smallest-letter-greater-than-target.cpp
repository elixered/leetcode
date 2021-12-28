class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size()-1;
        char ans = letters[0];
        while(low<=high)
        {
            int mid = (low+high)/2;
            if(letters[mid]>target)
            {
                ans = letters[mid];
                high = mid-1;
            }
            else
                low = mid+1;
        }
        return ans;
    }
};