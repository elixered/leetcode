class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> nums;
        nums.push_back(-1);
        for(int i=n-1; i>=0; i--)
        {
            for(int j=0; j<n; j++)
            {
                if((n-1-i)%2==0)
                    nums.push_back(board[i][j]);
                else nums.push_back(board[i][n-j-1]);
            }
        }
        queue<int> q;
        q.push(1);
        int count = 0;
        unordered_set<int> visited;
        visited.insert(1);
        while(!q.empty())
        {
            int sz = q.size();
            for(int k=0; k<sz; k++)
            {
                int curr = q.front();
                q.pop();
                if(curr==n*n)
                    return count;
                for(int i=1; i<=6; i++)
                {
                    int next = curr+i;
                    if(visited.find(next)!=visited.end())
                        continue;
                    else visited.insert(next);
                    if(next>n*n) continue;
                    if(nums[next]==-1)
                        q.push(next);
                    else q.push(nums[next]);
                }
            }
            count++;
        }
        return -1;
    }
};