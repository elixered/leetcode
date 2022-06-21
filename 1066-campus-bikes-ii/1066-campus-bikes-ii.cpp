class Solution {
public:
    int dp[11][2050];
    int recur(vector<vector<int>>& workers, vector<vector<int>>& bikes, int idx,  int visited){
        if(idx==workers.size()){
            return 0;
        }
        if(dp[idx][visited]!=-1) return dp[idx][visited];
        int temp = pow(10,5);
        for(int i=0; i<bikes.size(); i++){
            if((visited&(1<<i))==0){
                visited += 1<<i;
                int dis= abs(workers[idx][0]-bikes[i][0])+abs(workers[idx][1]-bikes[i][1]);
			int temp2=recur(workers,bikes,idx+1,visited);
			temp=min(temp,temp2+dis);
                visited -= 1<<i;
            }
        }
        return dp[idx][visited] = temp;
    }
    
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        memset(dp,-1,sizeof(dp));
        int n = bikes.size();
        return recur(workers,bikes,0,0);
    }
};

// class Solution {
// public:
// 	vector<vector<int>> dp;
// 	int dfs(int cur,vector<vector<int>>& workers, vector<vector<int>>& bikes, int used)
// 	{
// 		if(cur>=workers.size())
// 		{
// 			return 0;
// 		}
// 		if(dp[cur][used]) return dp[cur][used];


// 		int temp=INT_MAX;
// 		for(int i=0;i<bikes.size();i++)
// 		{
// 			if((used>>i)&1) continue;
// 			used+=(1<<i);
// 			int dis= abs(workers[cur][0]-bikes[i][0])+abs(workers[cur][1]-bikes[i][1]);
// 			int temp2=dfs(cur+1,workers,bikes,used);
// 			temp=min(temp,temp2+dis);
// 			used-=(1<<i);

// 		}

// 		dp[cur][used]=temp;
// 		return temp;
// 	}
// 	int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
// 		int n=workers.size();
// 		int m=bikes.size();
// 		dp.assign(n,vector<int>(1<<m,0));
// 		return dfs(0,workers,bikes,0);  
// 	}
// };