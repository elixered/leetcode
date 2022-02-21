class Solution {
public:
    int numTeams(vector<int>& arr) {
        int n = arr.size();
        int result = 0;
        for(int i = 1 ; i < n-1 ; i++){
            int leftSmall = 0, leftLarge = 0;
            int rightSmall = 0, rightLarge = 0;
            //left part
            for(int j = 0 ; j < i ; j++){
                if(arr[j] < arr[i]){
                    leftSmall++;
                }
                if(arr[j] > arr[i]){
                    leftLarge++;
                }
            }
            //right part
            for(int j = i+1 ; j < n ; j++){
                if(arr[j] < arr[i]){
                    rightSmall++;
                }
                if(arr[j] > arr[i]){
                    rightLarge++;
                }
            }
            result += leftSmall * rightLarge + leftLarge * rightSmall;
        }
        return result;
    }
};