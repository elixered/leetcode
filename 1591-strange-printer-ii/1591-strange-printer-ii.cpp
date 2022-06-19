class Solution {
public:
    bool isPrintable(vector<vector<int>>& grid) {
        unordered_set<int>st;
        map<int,vector<int>>row,col;
        int n=grid.size(),m=grid[0].size();
		
		for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                st.insert(grid[i][j]);
        }
        
        for(auto it:st)
        {
            int mn1=max(n,m),mn2=max(m,n),mx1=0,mx2=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(grid[i][j]==it)
                    {
                        mn1=min(i,mn1);
                        mx1=max(i,mx1);
                        mn2=min(j,mn2);
                        mx2=max(j,mx2);
                    }
                }
            }
            row[it].push_back(mn1);
            row[it].push_back(mx1);
            col[it].push_back(mn2);
            col[it].push_back(mx2);
        }
		
        vector<vector<int>>graph(61,vector<int>());
        int indeg[61];
        memset(indeg,0,sizeof indeg);
        for(auto it:st)
        {
            int mnr=row[it][0],mxr=row[it][1],mnc=col[it][0],mxc=col[it][1];
            set<int>st2;
            for(int i=mnr;i<=mxr;i++)
            {
                for(int j=mnc;j<=mxc;j++)
                {
                    if(it!=grid[i][j])
                        st2.insert(grid[i][j]);
                }
            }
            indeg[it]+=st2.size();
            for(auto pt:st2)
                graph[pt].push_back(it);
        }
		
		// Standard Topological Sort 
        int cnt=0;
        queue<int>q;
        for(int i=1;i<=61;i++)
        {
            if(st.find(i)!=st.end() and indeg[i]==0)
                q.push(i);
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            cnt++;
            for(auto it:graph[x])
            {
                indeg[it]--;
                if(indeg[it]==0)
                    q.push(it);
            }
        }
        if(cnt==st.size())
            return true;
        return false;
        
        
    }
};