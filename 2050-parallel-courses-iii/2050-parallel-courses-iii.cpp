class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
              vector<vector<int>> adjList(n);
        vector<int> inDegree(n),cTime(n,0);
		
        for(auto &r:relations) {          
            adjList[r[0]-1].push_back(r[1]-1);
			inDegree[r[1]-1]++;
		}
        queue<pair<int,int>> q;
		
        for(int i=0;i<n;i++)            
            if(!inDegree[i])
                q.push({i,0});

        while(!q.empty()) {
            auto [node,t]=q.front();   
            q.pop();
			
            int completionTime=t+time[node];
            cTime[node]=completionTime;
            
			for(int &n:adjList[node]) {
                cTime[n]=max(cTime[n],completionTime);
				
                if(!--inDegree[n])       
                    q.push({n,cTime[n]});
            }
        }
        return *max_element(cTime.begin(),cTime.end());
    }
};