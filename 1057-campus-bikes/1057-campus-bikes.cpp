class Solution {
public:
    int findDistance(vector<int>& worker, vector<int>& bike) {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
    
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<tuple<int, int, int>> allTriplets;
        
        for (int worker = 0; worker < workers.size(); worker++) {
            for (int bike = 0; bike < bikes.size(); bike++) {
                int distance = findDistance(workers[worker], bikes[bike]);        
                allTriplets.push_back({distance, worker, bike});
            }
        }
        
        sort(allTriplets.begin(), allTriplets.end());  
        
        vector<int> bikeStatus(bikes.size(), false);
        vector<int> workerStatus(workers.size(), -1);
        int pairCount = 0;
        
        for (auto[dist, worker, bike] : allTriplets) { 
            // If both worker and bike are free, assign them to each other
            if (workerStatus[worker] == -1 && !bikeStatus[bike]) {
                bikeStatus[bike] = true;
                workerStatus[worker] = bike;
                pairCount++;
                
                // If all the workers have the bike assigned, we can stop
                if (pairCount == workers.size()) {
                    return workerStatus;
                }
            }
        }
        
        return workerStatus;
    }
};