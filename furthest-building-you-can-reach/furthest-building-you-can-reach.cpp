class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        int i=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        while(i<n-1)
        {
            int gap = heights[i+1]-heights[i];
            if(gap>0)
            {
                if(ladders>0)
                {
                    ladders--;
                    pq.push(gap);
                }
                else
                {
                    if(!pq.empty() && pq.top()<gap)
                    {
                        int minLadder = pq.top();

                            pq.pop();
                            if(bricks<minLadder)
                                return i;
                            else
                            bricks -= minLadder;
                            pq.push(gap);
                        }
                        else
                        {
                            if(bricks<gap)
                                return i;
                            else bricks -= gap;
                        }
                    }
            }
            i++;
        }
        return n-1;
    }
};