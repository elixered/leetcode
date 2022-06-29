class Solution {
public:
    
	int min_diff(vector<vector<int>> & mat,int row,int curr,int target,vector<vector<int>> & dp){

		int rows=mat.size();
		int cols=mat[row].size();

		  // if know the answer for this already simply return 
		  if(dp[row][curr]!=-1){
			return dp[row][curr];
		}

		// only one row left so take the one which gives minimum difference with target
		if(row==rows-1){

			int diff=INT_MAX;
			for(int col=0;col<cols;col++){
				int cd=abs(target-(curr+mat[row][col]));
				diff=min(diff,cd);
			}

			// remember the result
			dp[row][curr]=diff;
			return diff;
		}

		int bdiff=INT_MAX;
		for(int col=0;col<cols;col++){
			// pass on the choice to next row
			int cdiff=min_diff(mat,row+1,curr+mat[row][col],target,dp);
			// update if we get a better choice 
			bdiff=min(bdiff,cdiff);

			// we can't have a better choice then this so stop here
			if(bdiff==0){
				break;
			}
		}


		dp[row][curr]=bdiff;
		return bdiff;
	}

	int minimizeTheDifference(vector<vector<int>>& mat, int target) {

	int rows=mat.size();
	int cols=mat[0].size();

	// grid with each row having unique values
	vector<vector<int>> grid;

	for(int row=0;row<rows;row++){
		unordered_map <int,bool> unique; 
		for(int col=0;col<cols;col++){
			unique[mat[row][col]]=true;
		}

		vector<int> cr;
		for(auto elem:unique){
			cr.push_back(elem.first);
		}

		grid.push_back(cr);
	}

	vector<vector<int>> dp(rows,vector<int>(5041,-1));
	int ans=min_diff(grid,0,0,target,dp);
	return ans;
	}
};