class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int low = 0;
        int high = people.size()-1;
        sort(people.begin(),people.end());
        int count = 0;
        while(low<high)
        {
            if(people[low]+people[high]<=limit)
            {
                high--;
                low++;
                count++;
            }
            else
            {
                high--;
                count++;
            }
        }
        if(low==high)
            count++;
        return count;
    }
};