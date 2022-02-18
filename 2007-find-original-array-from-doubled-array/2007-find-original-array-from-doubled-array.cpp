class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        vector<int> result;
        
        sort(begin(changed), end(changed));
		/*
			Since I have sorted the array, so I will find the twice of a number
			If I get it, well and good, check further
			else, return {}
		*/
        for(int i = 0; i<n; i++) {
            int num = changed[i];
            if(num < 0) continue;
            
            auto idx = lower_bound(begin(changed)+i+1, end(changed), 2*num);
            
            if(idx != end(changed) && *idx == 2*num) {
                *idx = -1; //mark it
                result.push_back(num); //found it
            } else {
                return {}; //oooops
            }
        }
        
        return result;
    }
};