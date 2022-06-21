class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        multiset<int> st;
        int n = heights.size();
        for(int i=0; i<n-1; i++){
            int jump = heights[i+1] - heights[i];
            if(jump <= 0) continue;
            if(ladders > 0){
                ladders--;
                st.insert(jump);
            }
            else{
                if(!st.empty()){
                    int minLadder = *st.begin();
                    if(minLadder >= jump){
                        if(bricks >= jump)
                            bricks -= jump;
                        else return i;
                    }
                    else{
                        if(bricks >= minLadder){
                            bricks -= minLadder;
                            st.erase(st.begin());
                            st.insert(jump);
                        }
                        else return i;
                    }
                }
                else if(bricks >= jump)
                            bricks -= jump;
                        else return i;
            }
        }
        return n-1;
    }
};